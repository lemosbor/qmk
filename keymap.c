#include QMK_KEYBOARD_H // компиляция по QMK
//#include "eeconfig.h"
//#include "preonic.h"
//#include "action_layer.h"
//#include "process_unicode.h" // для юникода
// #include "keymap_russian.h" // подгрузка русских букв  qmk compile -kb preonic/rev3 -km pri
// UNICODEMAP_ENABLE = yes in rules.mk

#define L_OSNOVA 0 // слой 0 (основной)
#define L_SERV 1 // слой 1 (сервисный)

typedef struct { //назначение структуры нажатий https://docs.qmk.fm/#/feature_tap_dance?id=how-to-use
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,    
    PER_LAY, // кнопка преключения раскладки
    VYH, // Вых / альт+Ф4
    TABB, // таб / альт+таб
    WEMO, // окно / окно+точка
    RU_AN, // кнопка Р/А
};

enum combo_events { // обозначение комбо-команд
comb_TOCH,
comb_ZAP,
comb_TZ,
comb_DT,
comb_DEF,
comb_TIRE,
comb_VOS,
comb_VOP,
comb_REG1,
comb_REG2,
comb_PROB1,
comb_PROB2,
comb_NACH,
comb_KON,
comb_LEV,
comb_PRAV,
comb_VERH,
comb_VNIZ,
comb_VSH,
comb_VVOD,
comb_UDL,
comb_TAB,
comb_VIH,
comb_KOP1,
comb_KOP2,
comb_VST1,
comb_VST2,
comb_UPR1,
comb_UPR2,
comb_OTM,
comb_N1,
comb_N2,
comb_N3,
comb_N4,
comb_N5,
comb_N6,
comb_N7,
comb_N8,
comb_N9,
comb_N0,
};

uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий
void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* Основа
 * ,-----------------------------------------------------------------------------------.
 * | !/\| | "@′² | ,%×³ | ;$₽§ | -—_− |  УД  | =#№~ | :+^÷ | ?&<° | .*>  | («[{ | )»]} |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   C  |   V  |   U  |   ,  |   [  |  ТАБ |   X  |   H  |   P  |   L  |   M  |   J  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   I  |   A  |   E  |   O  |   S  |  ВЫХ |   ]  |   K  |   N  |   T  |   W  |   R  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   "  |   /  |   Q  |   Y  |   .  |  ВШ  |   F  |   G  |   D  |   B  |   ;  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  |Окно  | ДОП  |  Б/Ц |пробел|  РЕГ | ВВОД |пробел|  Р/А | БЛОК |  НАЧ | КОН  |
 * `-----------------------------------------------------------------------------------'
ц ь у ч ш ъ х п л м й
и а е о с щ к н т в р
э ё ы я ю ф г д б ж з
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  KC_1,    KC_2,     KC_3,   KC_4,       KC_5,    KC_DEL,  KC_EQL,  KC_6,   KC_7,     KC_8,    KC_9,    KC_0, \
  KC_C,    KC_V,     KC_U,   KC_COMM,    KC_LBRC, TD(TABB),KC_X ,   KC_H,   KC_P,     KC_L,    KC_M,    KC_J,  \
  KC_I,    KC_A,     KC_E,   KC_O,       KC_S,    TD(VYH), KC_RBRC, KC_K,   KC_N,     KC_T,    KC_W,    KC_R, \
  KC_QUOT, KC_SLSH,  KC_Q,   KC_Y,       KC_DOT,  KC_BSPC, KC_F,    KC_G,   KC_D,     KC_B,    KC_SCLN, KC_Z, \
  KC_LCTL, TD(WEMO), KC_RALT,TD(PER_LAY),KC_SPC,  KC_LSFT, KC_ENT,  KC_SPC, TD(RU_AN),KC_LOCK, KC_HOME, KC_END  \
),
/* сервисная.
 * ,-----------------------------------------------------------------------------------.
 * | ярче |темнее| тихо |сл.пес| вверх|  УД  |  Ф10 |  Ф11 |  Ф12 |   *  |   /  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  коп |   ↑  |  вст | вырез| вниз |  ТАБ |  Ф7  |  Ф8  |  Ф9  |   7  |   8  |   9  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ←  |   ↓  |   →  | отмен|цвет в|  ВЫХ |  Ф4  |  Ф5  |  Ф6  |   4  |   5  |   6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | М.ЛК |  м↑  | М.ПК |  ПЕЧ |цвет р|  ВШ  |  Ф1  |  Ф2  |  Ф3  |   1  |   2  |   3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  м←  |  м↓  |  м→  |  Б/Ц |пробел|  РЕГ | ВВОД | ВСТ  |  ЦИФ |   \  |   0  |   .  |
 * `-----------------------------------------------------------------------------------'
 */ 
[L_SERV] = LAYOUT_preonic_grid( \
  KC_BRIU,  KC_BRID,  KC_MUTE,  KC_MNXT,    KC_PGUP, KC_DEL,  KC_F10, KC_F11, KC_F12, KC_PAST, KC_PSLS, KC_PMNS, \
  C(KC_INS),KC_UP,    S(KC_INS),C(KC_X),    KC_PGDN, TD(TABB),KC_F7,  KC_F8,  KC_F9,  KC_P7,   KC_P8,   KC_P9, \
  KC_LEFT,  KC_DOWN,  KC_RGHT,  C(KC_Z),    RGB_TOG, TD(VYH), KC_F4,  KC_F5,  KC_F6,  KC_P4,   KC_P5,   KC_P6, \
  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_PSCR,    RGB_MOD, KC_BSPC, KC_F1,  KC_F2,  KC_F3,  KC_P1,   KC_P2,   KC_P3, \
  KC_MS_L,  KC_MS_D,  KC_MS_R,  TD(PER_LAY),KC_SPC,  KC_LSFT, KC_ENT, KC_SPC, KC_NLCK,KC_BSLS, KC_P0,   KC_PDOT \
)
}; 
// задаем сочитание клавиш (комбо). Прописать их количество в файле config
const uint16_t PROGMEM TOCH_combo[] = {KC_O, KC_N, COMBO_END};
const uint16_t PROGMEM ZAP_combo[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM TZ_combo[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM DT_combo[] = {KC_O, KC_T, COMBO_END};
const uint16_t PROGMEM DEF_combo[] = {KC_A, KC_W, COMBO_END};
const uint16_t PROGMEM TIRE_combo[] = {KC_I, KC_R, COMBO_END};
const uint16_t PROGMEM VOS_combo[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM VOP_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM REG1_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM REG2_combo[] = {KC_N, KC_L, COMBO_END};
const uint16_t PROGMEM PROB1_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM PROB2_combo[] = {KC_T, KC_W, COMBO_END};
const uint16_t PROGMEM NACH_combo[] = {KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM KON_combo[] = {KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM LEV_combo[] = {KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM PRAV_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM VERH_combo[] = {KC_L, KC_M, COMBO_END};
const uint16_t PROGMEM VNIZ_combo[] = {KC_B, KC_SCLN, COMBO_END};
const uint16_t PROGMEM VSH_combo[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM VVOD_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM UDL_combo[] = {KC_U, KC_COMM, COMBO_END};
const uint16_t PROGMEM TAB_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM VIH_combo[] = {KC_N, KC_R, COMBO_END};
const uint16_t PROGMEM KOP1_combo[] = {KC_A, KC_U, COMBO_END};
const uint16_t PROGMEM KOP2_combo[] = {KC_L, KC_W, COMBO_END};
const uint16_t PROGMEM VST1_combo[] = {KC_V, KC_E, COMBO_END};
const uint16_t PROGMEM VST2_combo[] = {KC_T, KC_M, COMBO_END};
const uint16_t PROGMEM UPR1_combo[] = {KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM UPR2_combo[] = {KC_D, KC_T, COMBO_END};
const uint16_t PROGMEM OTM_combo[] = {KC_V, KC_U, COMBO_END};
const uint16_t PROGMEM N1_combo[] = {KC_Y, KC_B, COMBO_END};
const uint16_t PROGMEM N2_combo[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM N3_combo[] = {KC_Y, KC_Z, COMBO_END};
const uint16_t PROGMEM N4_combo[] = {KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM N5_combo[] = {KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM N6_combo[] = {KC_Y, KC_R, COMBO_END};
const uint16_t PROGMEM N7_combo[] = {KC_Y, KC_L, COMBO_END};
const uint16_t PROGMEM N8_combo[] = {KC_Y, KC_M, COMBO_END};
const uint16_t PROGMEM N9_combo[] = {KC_Y, KC_J, COMBO_END};
const uint16_t PROGMEM N0_combo[] = {KC_Y, KC_HOME, COMBO_END};

//связываем комбо с функциональными клавишами и действиями
combo_t key_combos[COMBO_COUNT] = { 
[comb_TOCH] = COMBO_ACTION(TOCH_combo),
[comb_ZAP] = COMBO_ACTION(ZAP_combo),
[comb_TZ] = COMBO_ACTION(TZ_combo),
[comb_DT] = COMBO_ACTION(DT_combo),
[comb_DEF] = COMBO(DEF_combo, KC_PMNS),
[comb_TIRE] = COMBO_ACTION(TIRE_combo),
[comb_VOS] = COMBO_ACTION(VOS_combo),
[comb_VOP] = COMBO_ACTION(VOP_combo),
  [comb_REG1] = COMBO(REG1_combo, KC_LSFT), 
  [comb_REG2] = COMBO(REG2_combo, KC_RSFT),
  [comb_PROB1] = COMBO(PROB1_combo, KC_SPC),
  [comb_PROB2] = COMBO(PROB2_combo, KC_SPC),
  [comb_NACH] = COMBO(NACH_combo, KC_HOME),
  [comb_KON] = COMBO(KON_combo, KC_END),
  [comb_LEV] = COMBO(LEV_combo, KC_LEFT),
  [comb_PRAV] = COMBO(PRAV_combo, KC_RGHT),
  [comb_VERH] = COMBO(VERH_combo, KC_UP),
  [comb_VNIZ] = COMBO(VNIZ_combo, KC_DOWN),
  [comb_VSH] = COMBO(VSH_combo, KC_BSPC),
[comb_VVOD] = COMBO(VVOD_combo, KC_ENT),
  [comb_UDL] = COMBO(UDL_combo, KC_DEL),
  [comb_TAB] = COMBO(TAB_combo, KC_TAB),
  [comb_VIH] = COMBO(VIH_combo, KC_ESC),
[comb_KOP1] = COMBO_ACTION(KOP1_combo),
[comb_KOP2] = COMBO_ACTION(KOP2_combo),
[comb_VST1] = COMBO_ACTION(VST1_combo),
[comb_VST2] = COMBO_ACTION(VST2_combo),
  [comb_UPR1] = COMBO(UPR1_combo, KC_LCTL),
  [comb_UPR2] = COMBO(UPR2_combo, KC_RCTL),
[comb_OTM] = COMBO_ACTION(OTM_combo),
[comb_N1] = COMBO(N1_combo, KC_P1),
[comb_N2] = COMBO(N2_combo, KC_P2),
[comb_N3] = COMBO(N3_combo, KC_P3),
[comb_N4] = COMBO(N4_combo, KC_P4),
[comb_N5] = COMBO(N5_combo, KC_P5),
[comb_N6] = COMBO(N6_combo, KC_P6),
[comb_N7] = COMBO(N7_combo, KC_P7),
[comb_N8] = COMBO(N8_combo, KC_P8),
[comb_N9] = COMBO(N9_combo, KC_P9),
[comb_N0] = COMBO(N0_combo, KC_P0),
};

// действия для комбо
void process_combo_event(uint16_t combo_index, bool pressed) { 
  switch(combo_index) {
    case comb_ZAP: // запятая
      if (pressed) {
        register_code(KC_3);
        unregister_code(KC_3);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_TOCH: // точка
      if (pressed) {
        register_code(KC_8);
        unregister_code(KC_8);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_TZ: // точка c запятой
      if (pressed) {
        register_code(KC_4);
        unregister_code(KC_4);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_DT: // двоеточие
      if (pressed) {
        register_code(KC_6);
        unregister_code(KC_6);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_TIRE: // тире
      if (pressed) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        register_code(KC_LSFT);
        register_code(KC_5);
        unregister_code(KC_5);
        unregister_code(KC_LSFT);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_VOS: // !
      if (pressed) {
        register_code(KC_1);
        unregister_code(KC_1);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
     case comb_VOP: // ?
      if (pressed) {
        register_code(KC_7);
        unregister_code(KC_7);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_OTM: // отмена
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case comb_KOP1: // скопировать
      if (pressed) {
        tap_code16(LCTL(KC_INS));
      }
      break;
    case comb_KOP2: // скопировать
      if (pressed) {
        tap_code16(LCTL(KC_INS));
      }
      break;
    case comb_VST1: // вставить
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
    case comb_VST2: // вставить
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
  }
}

uint8_t cur_dance(qk_tap_dance_state_t *state) { // определение состояния двойного нажатия
    if (state->count == 1) { //если нажата один раз
        if (!state->pressed) return SINGLE_TAP; // если не удерживается, то Одиночное нажатие
        else return SINGLE_HOLD; // иначе Одиночное удержание
    } else if (state->count == 2) return DOUBLE_TAP; // если нажата два раза, то Двойное нажатие
    else return 8; // магическое число (на будущее)
}
static tap ql_tap_state = { // Инициализация двойного нажатия
    .is_press_action = true,
    .state = 0 // обнуление состояния
};

void ql_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия Б/Ц. Действие при нажатии
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: // одиночное нажатие
            if (layer_state_is(L_SERV)) { // проверка не назначен ли данный слой уже                
                layer_off(L_SERV); // если установлен, то отключить
            } else {
                layer_on(L_SERV); // если не установлен, то включить
            }
            break;
        case SINGLE_HOLD: // одиночное удержание. Временное переключение слоя
            layer_on(L_SERV);
            break;
    }
};
void ql_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    if (ql_tap_state.state == SINGLE_HOLD) { //при одиночном нажатии
        layer_off(L_SERV); // отключить слой
    }
    ql_tap_state.state = 0; // обнуление состояния
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия Р/А. Действие при нажатии
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code(KC_CAPS); break; // нажатие КАПС
        case SINGLE_HOLD: register_code(KC_CAPS); break; // нажатие КАПС
    }
}
void x_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_CAPS); break; // снятие КАПС
        case SINGLE_HOLD: register_code(KC_CAPS); break; // нажатие КАПС
    }
    ql_tap_state.state = 0; // обнуление состояния
};

qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [PER_LAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275), // Б/Ц
    [VYH] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)), // выход или альт+ф4
    [TABB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LALT(KC_TAB)), // таб или альт+таб https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
    [WEMO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_DOT)), // вин или эмодзи
    [RU_AN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset), // Р/А
};

void matrix_init_user (void) { //постоянная активация NUMLOCK https://www.reddit.com/r/olkb/comments/5mxtfp/qmk_num_lock/
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) { // или https://github.com/qmk/qmk_firmware/issues/2164
      register_code(KC_NUMLOCK);
      unregister_code(KC_NUMLOCK);
  }
};

//void eeconfig_init_user(void) {  // EEPROM is getting reset! use the non noeeprom versions, to write these values to EEPROM too https://www.reddit.com/r/olkb/comments/e0hurb/trying_to_set_color_based_on_active_layer_in_qmk/
//  rgblight_enable(); // включить подсветку по-умолчанию
//  rgblight_sethsv_white();  // установить белый цвет
//  rgblight_mode(RGBLIGHT_MODE_BREATHING); // установить режим Дыхание
//};

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_config_t rgblight_config;
  switch(biton32(state)) {
  case L_SERV: //если сервисный слой
    rgblight_enable_noeeprom(); //включаем подсветку
    rgblight_sethsv_noeeprom(HSV_RED); //зажигаем красный
    break;
  default:
    rgblight_config.raw = eeconfig_read_rgblight(); //читаем статус подсветки
    if (rgblight_config.enable) { //если включена, 
        rgblight_sethsv_noeeprom(HSV_WHITE); //то устанавливаем белую
    } else { //иначе
        rgblight_disable_noeeprom(); // отключаем
    }
    break;
}
return state;
}
