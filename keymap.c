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
    PROB_REG // пробел / регистр
};

enum combo_events {
    EU_REG, // РЕГ
    NW_REG, // РЕГ
    IO_VSH,
    LR_UDL,
    IN_NACH,
    ER_KON,
    IA_LEV,
    TR_PRAV,
    WD_VERH,
    LT_VNIZ,
    IU_TAB,
    QD_VIH,
    QE_UPR,
    ND_UPR,
    EO_ZAP, // запятая
    NL_TOCH,// точка
    AU_KOP,
    WT_KOP,
    QO_VST,
    LD_VST,
    OZ_OTM,
    AE_VVOD,
    NT_VVOD,
    AO_PROB,
    LT_PROB,
};

uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий
void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* Основа
 * ,-----------------------------------------------------------------------------------.
 * | !/\| | "@′² | ,%×³ | ;$₽§ | -—_− |  УД  | =#№~ | :+^÷ | ?&<° | .*>  | («[{ | )»]} |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   X  |   Q  |   U  |   Z  |   F  |  ТАБ |   ]  |   J  |   G  |   W  |   D  |   ,  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   I  |   A  |   O  |   E  |   S  |  ВЫХ |   [  |   K  |   N  |   L  |   T  |   R  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   "  |   /  |   .  |   V  |   Y  |  ВШ  |   C  |   P  |   M  |   B  |   H  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Окно | ДОП  |  УПР |  Б/Ц |пробел|  РЕГ | ВВОД |пробел|  Р/А | БЛОК |  НАЧ | КОН  |
 * `-----------------------------------------------------------------------------------'
ъ	ы	у	з	ф	щ	й	г	в	д	ч
и	а	о	е	с	ш	к	н	л	т	р
э	ё	ю	ь	я	ц	п	м	б	х	ж
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  KC_1,    KC_2,     KC_3,   KC_4,        KC_5,    KC_DEL,   KC_EQL,  KC_6,        KC_7,     KC_8,     KC_9,     KC_0, \
  KC_X,    KC_Q,     KC_U,   KC_Z,        KC_F,    TD(TABB), KC_RBRC, KC_J,        KC_G,     KC_W,     KC_D,    KC_COMM,  \
  KC_I,    KC_A,     KC_O,   KC_E,        KC_S,    TD(VYH),  KC_LBRC, KC_K,        KC_N,     KC_L,     KC_T,    KC_R, \
  KC_QUOT, KC_SLSH,  KC_DOT, KC_V,        KC_Y,    KC_BSPC,  KC_C,    KC_P,        KC_M,     KC_B,     KC_H,    KC_SCLN, \
  TD(WEMO), KC_RALT, KC_LCTL, TD(PER_LAY), KC_SPC,  KC_LSFT,  KC_ENT,  TD(PROB_REG),TD(RU_AN),KC_LOCK, KC_HOME, KC_END  \
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
  KC_BRIU,  KC_BRID,  KC_MUTE,  KC_MNXT,    KC_PGUP, KC_DEL,  KC_F10, KC_F11,      KC_F12, KC_PAST, KC_PSLS, KC_PMNS, \
  C(KC_INS),KC_UP,    S(KC_INS),C(KC_X),    KC_PGDN, TD(TABB),KC_F7,  KC_F8,       KC_F9,  KC_P7,   KC_P8,   KC_P9, \
  KC_LEFT,  KC_DOWN,  KC_RGHT,  C(KC_Z),    RGB_TOG, TD(VYH), KC_F4,  KC_F5,       KC_F6,  KC_P4,   KC_P5,   KC_P6, \
  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_PSCR,    RGB_MOD, KC_BSPC, KC_F1,  KC_F2,       KC_F3,  KC_P1,   KC_P2,   KC_P3, \
  KC_MS_L,  KC_MS_D,  KC_MS_R,  TD(PER_LAY),KC_SPC,  KC_LSFT, KC_ENT, TD(PROB_REG),KC_NLCK,KC_BSLS, KC_P0,   KC_PDOT \
)
}; //beta.docs.qmk.fm/using-qmk/advanced-keycodes/keycodes_us_ansi_shifted
// задаем сочитание клавиш для комбо

const uint16_t PROGMEM ZAP_combo[] = {KC_E, KC_O, COMBO_END}; // 1 запятаяlt
const uint16_t PROGMEM TOCH_combo[] = {KC_N, KC_L, COMBO_END}; // 2 точка
const uint16_t PROGMEM REG1_combo[] = {KC_E, KC_U, COMBO_END}; // 3 РЕГaenteanteantioiolrlr
const uint16_t PROGMEM REG2_combo[] = {KC_N, KC_W, COMBO_END}; // 4 РЕГao
const uint16_t PROGMEM VSH_combo[] = {KC_I, KC_O, COMBO_END}; // 7 РЕГ
const uint16_t PROGMEM UDL_combo[] = {KC_L, KC_R, COMBO_END}; // 8 РЕГrllrlriooiiooi
const uint16_t PROGMEM VVOD1_combo[] = {KC_A, KC_E, COMBO_END}; // 5 РЕГ
const uint16_t PROGMEM VVOD2_combo[] = {KC_N, KC_T, COMBO_END}; // 6 РЕГ, . euleulnwoao
const uint16_t PROGMEM PROB1_combo[] = {KC_A, KC_O, COMBO_END}; // 1 запятая, kn. eoueeuluellwnoea. tnnttnnt, 
const uint16_t PROGMEM PROB2_combo[] = {KC_L, KC_T, COMBO_END}; // 2 точкаaoaoeueuwnownnwo. 
const uint16_t PROGMEM NACH_combo[] = {KC_I, KC_N, COMBO_END}; // 9 РЕГ
const uint16_t PROGMEM KON_combo[] = {KC_E, KC_R, COMBO_END}; // 10 РЕГ
const uint16_t PROGMEM LEV_combo[] = {KC_I, KC_A, COMBO_END}; // 11 РЕГ
const uint16_t PROGMEM PRAV_combo[] = {KC_T, KC_R, COMBO_END}; // 12 РЕГ
const uint16_t PROGMEM VERH_combo[] = {KC_W, KC_D, COMBO_END}; // 13 запятая
const uint16_t PROGMEM VNIZ_combo[] = {KC_B, KC_H, COMBO_END}; // 14 точка
const uint16_t PROGMEM TAB_combo[] = {KC_I, KC_U, COMBO_END}; // 15 РЕ,Г
const uint16_t PROGMEM VIH_combo[] = {KC_Q, KC_D, COMBO_END}; // 16 РЕГ
const uint16_t PROGMEM UPR1_combo[] = {KC_Q, KC_E, COMBO_END}; // 17 РЕГ, , , ,РЕГCOMBO_END
const uint16_t PROGMEM UPR2_combo[] = {KC_N, KC_D, COMBO_END}; // 18 РЕГCOMBO_END
const uint16_t PROGMEM KOP1_combo[] = {KC_A, KC_U, COMBO_END}; // 21 РЕГ
const uint16_t PROGMEM KOP2_combo[] = {KC_W, KC_T, COMBO_END}; // 22 РЕГ
const uint16_t PROGMEM VST1_combo[] = {KC_Q, KC_O, COMBO_END}; // 23 РЕГ
const uint16_t PROGMEM VST2_combo[] = {KC_L, KC_D, COMBO_END}; // 24 РЕ
const uint16_t PROGMEM OTM_combo[] = {KC_O, KC_Z, COMBO_END}; // 24 РЕГ

combo_t key_combos[COMBO_COUNT] = {
  [EU_REG] = COMBO(REG1_combo, KC_LSFT), 
  [NW_REG] = COMBO(REG2_combo, KC_RSFT),
  [AE_VVOD] = COMBO_ACTION(VVOD1_combo),
  [NT_VVOD] = COMBO_ACTION(VVOD2_combo),
  [IO_VSH] = COMBO(VSH_combo, KC_BSPC),
  [LR_UDL] = COMBO(UDL_combo, KC_DEL),
  [IN_NACH] = COMBO(NACH_combo, KC_HOME),
  [ER_KON] = COMBO(KON_combo, KC_END),
  [IA_LEV] = COMBO(LEV_combo, KC_LEFT),
  [TR_PRAV] = COMBO(PRAV_combo, KC_RGHT),
  [WD_VERH] = COMBO(VERH_combo, KC_UP),
  [LT_VNIZ] = COMBO(VNIZ_combo, KC_DOWN),
  [AO_PROB] = COMBO_ACTION(PROB1_combo),
  [LT_PROB] = COMBO_ACTION(PROB2_combo),
  [IU_TAB] = COMBO(TAB_combo, KC_TAB),
  [QD_VIH] = COMBO(VIH_combo, KC_ESC),
  [QE_UPR] = COMBO(UPR1_combo, KC_LCTL),
  [ND_UPR] = COMBO(UPR2_combo, KC_RCTL),
  [EO_ZAP] = COMBO_ACTION(ZAP_combo),
  [NL_TOCH] = COMBO_ACTION(TOCH_combo),
  [AU_KOP] = COMBO_ACTION(KOP1_combo),
  [WT_KOP] = COMBO_ACTION(KOP2_combo),
  [QO_VST] = COMBO_ACTION(VST1_combo),
  [LD_VST] = COMBO_ACTION(VST2_combo),
  [OZ_OTM] = COMBO_ACTION(OTM_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EO_ZAP: // запятая
      if (pressed) {
        register_code(KC_3);
        unregister_code(KC_3);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case NL_TOCH: // точка
      if (pressed) {
        register_code(KC_8);
        unregister_code(KC_8);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case OZ_OTM: // точка
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case AU_KOP: // точка
      if (pressed) {
        tap_code16(LCTL(KC_INS));
      }
      break;
    case WT_KOP: // точка
      if (pressed) {
        tap_code16(LCTL(KC_INS));
      }
      break;
    case QO_VST: // точка
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
    case LD_VST: // точка
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
    case AE_VVOD: // точка
      if (pressed) {
        register_code(KC_ENT);
        unregister_code(KC_ENT);
      }
      break;
    case NT_VVOD: // точка
      if (pressed) {
        register_code(KC_ENT);
        unregister_code(KC_ENT);
      }
      break;
    case AO_PROB: // точка
      if (pressed) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case LT_PROB: // точка
      if (pressed) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
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
        case SINGLE_TAP: register_code(KC_CAPS); break;
        case SINGLE_HOLD: register_code(KC_CAPS); break;
    }
}
void x_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_CAPS); break;
        case SINGLE_HOLD: register_code(KC_CAPS); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};

void prreg_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия Р/А. Действие при нажатии
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code(KC_SPC); break;
        case SINGLE_HOLD: register_code(KC_LSFT); break;
        case DOUBLE_TAP: register_code(KC_BSPC); break;
    }
}
void prreg_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_SPC); break;
        case SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code(KC_BSPC); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};


qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [PER_LAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275), // Б/Ц
    [VYH] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)), // выход или альт+ф4
    [TABB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LALT(KC_TAB)), // таб или альт+таб https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
    [WEMO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_DOT)), // вин или эмодзи
    [RU_AN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset), // Р/А
    [PROB_REG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, prreg_finished, prreg_reset) // к/в
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
