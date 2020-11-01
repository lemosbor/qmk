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

enum combos {
  WD_ENT
};

uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий
void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* Основа
 * ,-----------------------------------------------------------------------------------.
 * | !/\| | "@′² | ,%×³ | ;$₽§ | -—_− |  УД  | =#№~ | :+^÷ | ?&<° | .*>  | («[{ | )»]} |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   X  |   Q  |   U  |   ,  |   F  |  ТАБ |   /  |   J  |   G  |   W  |   M  |   C  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   I  |   E  |   O  |   A  |   S  |  ВЫХ |   D  |   K  |   N  |   L  |   T  |   R  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   "  |   .  |   Y  |   V  |   [  |  ВШ  |   ]  |   Z  |   P  |   B  |   H  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  | Окно | ДОП  |  Б/Ц |пробел|  РЕГ | ВВОД |пробел|  Р/А | БЛОК |  НАЧ | КОН  |
 * `-----------------------------------------------------------------------------------'
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  KC_1,    KC_2,     KC_3,   KC_4,        KC_5,    KC_DEL,   KC_EQL,  KC_6,        KC_7,     KC_8,     KC_9,     KC_0, \
  KC_X,    KC_Q,     KC_U,   KC_COMM,     KC_F,    TD(TABB), KC_SLSH, KC_J,        KC_G,     KC_W,     KC_M,    KC_C,  \
  KC_I,    KC_E,     KC_O,   KC_A,        KC_S,    TD(VYH),  KC_D,    KC_K,        KC_N,     KC_L,     KC_T,    KC_R, \
  KC_QUOT, KC_DOT,   KC_Y,   KC_V,        KC_LBRC, KC_BSPC,  KC_RBRC, KC_Z,        KC_P,     KC_B,     KC_H,    KC_SCLN, \
  KC_LCTL, TD(WEMO), KC_RALT,TD(PER_LAY), KC_SPC,  KC_LSFT,  KC_ENT,  TD(PROB_REG),TD(RU_AN),KC_LOCK, KC_HOME, KC_END  \
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

const uint16_t PROGMEM wd_combo[] = {KC_W, KC_D, COMBO_END}; // задаем сочитание клавиш для комбо

combo_t key_combos[COMBO_COUNT] = {
  [WD_ENT] = COMBO(wd_combo, KC_ENT) // определяем действие для комбо
};

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