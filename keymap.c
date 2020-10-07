#include QMK_KEYBOARD_H // компиляция по QMK
//#include "eeconfig.h"
//#include "preonic.h"
//#include "action_layer.h"
//#include "process_unicode.h" // для юникода
// #include "keymap_russian.h" // подгрузка русских букв  qmk compile -kb preonic/rev3 -km pri
// UNICODEMAP_ENABLE = yes in rules.mk

#define L_OSNOVA 0 // слой 0 (основной)
#define L_SERV 1 // слой 1 (сервисный)
bool bnumlock = false;
bool numlock_changed = false;

typedef struct { //назначение структуры нажатий https://docs.qmk.fm/#/feature_tap_dance?id=how-to-use
    bool is_press_action;
    uint8_t state;
} tap;
enum {  // сопоставляем типы нажатий
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP
};

enum {
    PER_LAY, // кнопка преключения раскладки
    VVERH, // кнопка вверх
    VNIZ, // кнопка вниз
    VYH, // Вых / альт+Ф4
    TABB, // таб / альт+таб
    WEMO, // окно / окно+точка
    RU_AN, // кнопка Р/А
    KOPY
};
uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий
void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* Основа
 * ,-----------------------------------------------------------------------------------.
 * | -—_- | !'`′ | "@~' | ,%°× |  ;$<₽| №#>§ | :^\÷ | ?&„→ | .*"* | («[{ | )»]} |  ВШ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ТАБ  |   X  |   Q  |   U  |   ;  |   F  |   H  |   G  |   L  |   M  |   J  |   ,  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Вых  |   I  |   E  |   O  |   A  |   S  |   D  |   W  |   T  |   N  |   R  |   Z  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | РЕГ  |   Y  |   C  |   V  |   [  |   ]  |   P  |   K  |   B  |   .  |   ↑  | ВВОД |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  | Окно | ДОП  | к/в  |  Р/А |    пробел   |  Б/Ц |  УД  |   ←  |   ↓  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  KC_MINS,  KC_1,    KC_2,  KC_5,   KC_4,   KC_3,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  TD(TABB),  KC_X,    KC_Q,    KC_U,    KC_SCLN ,    KC_F,    KC_H,    KC_G,    KC_L,    KC_M,    KC_J,    KC_COMM,  \
  TD(VYH),  KC_I,    KC_E,    KC_O,    KC_A,    KC_S,   KC_D,    KC_W,    KC_T,    KC_N,    KC_R, KC_Z, \
  KC_LSFT, KC_Y,    KC_C,    KC_V,    KC_LBRC ,    KC_RBRC,    KC_P,    KC_K,    KC_B, KC_DOT,  KC_UP, KC_ENT,  \
  KC_LCTL, TD(WEMO), KC_LALT, TD(KOPY), TD(RU_AN), KC_SPC,  KC_SPC, TD(PER_LAY), KC_DEL, KC_LEFT, KC_DOWN,   KC_RGHT  \
),
/* сервисная
 * ,-----------------------------------------------------------------------------------.
 * | ярче |темнее|      |  ж   | вверх|  Ф10 |  Ф11 |  Ф12 |   *  |   /  |   -  |  ВШ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |сл.пес|      |      |      | вниз |  Ф7  |  Ф8  |  Ф9  |   7  |   8  |   9  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |цвет р|цвет в|  Ё " |  печ |  нач |  Ф4  |  Ф5  |  Ф6  |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | М.ЛК |М.верх| М.ПК |  Ъ/  |  кон |  Ф1  |  Ф2  |  Ф3  |   1  |   2  |   3  | ВВОД |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |М.лево|М.вниз|М.прав|  вст |  ЦИФ |    пробел   |  Б/Ц |   \  |   0  |   .  | ТАБ  |
 * `-----------------------------------------------------------------------------------'
 */
[L_SERV] = LAYOUT_preonic_grid( \
  KC_BRIU, KC_BRID, KC_NO, KC_NO, KC_PGUP, KC_F10, KC_F11, KC_F12, KC_PAST, KC_PSLS, KC_PMNS, KC_BSPC, \
  KC_MNXT, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_F7, KC_F8, KC_F9, KC_P7, KC_P8, KC_P9, KC_PPLS, \
  RGB_MOD, RGB_TOG, KC_QUOT, KC_PSCREEN, KC_HOME, KC_F4, KC_F5, KC_F6, KC_P4, KC_P5, KC_P6, KC_EQL, \
  KC_BTN1, KC_MS_U, KC_BTN2, KC_SLSH, KC_END, KC_F1, KC_F2, KC_F3, KC_P1, KC_P2, KC_P3, KC_ENT, \
  KC_MS_L, KC_MS_D, KC_MS_R, KC_INS, KC_NLCK, KC_SPC, KC_SPC, TD(PER_LAY), KC_BSLS, KC_P0, KC_PDOT, KC_TAB \
)
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
        case SINGLE_HOLD: register_code(KC_RALT); break;
    }
}
void x_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_CAPS); break;
        case SINGLE_HOLD: unregister_code(KC_RALT); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};

void kop_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия к/в. Действие при нажатии
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break; // нажатие.  Вставить
        case SINGLE_HOLD: register_code16(LCTL(KC_X)); break; // удержание. Вырезать
        case DOUBLE_TAP: register_code16(LCTL(KC_C)); break; // двойное нажатие.  Копировать
    }
};
void kop_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};

qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [PER_LAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275), // Б/Ц
    [VVERH] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_HOME), // вверх или домой
    [VNIZ] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_END), // вниз или в конец
    [VYH] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)), // выход или альт+ф4
    [TABB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LALT(KC_TAB)), // таб или альт+таб https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
    [WEMO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_DOT)), // вин или эмодзи
    [RU_AN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset), // Р/А
    [KOPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kop_finished, kop_reset) // Р/А
};

void led_set_kb(uint8_t usb_led) { //постоянная активация NUMLOCK https://www.reddit.com/r/olkb/comments/5mxtfp/qmk_num_lock/
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        bnumlock = true;
    } else {
        bnumlock = false;
    }
};

//void led_set_keymap(uint8_t usb_led) { //постоянная активация NUMLOCK
//  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
//    register_code(KC_NLCK);
//    unregister_code(KC_NLCK);
//  }
//};

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
    case 3: // для NUMLOCK
     if (record->event.pressed) {
       if(!bnumlock) {
           numlock_changed = true;
           register_code(KC_NLCK);
           unregister_code(KC_NLCK);
       }
       layer_on(3);
     } else {
       if(bnumlock && numlock_changed) {
           numlock_changed = false;
           register_code(KC_NLCK);
           unregister_code(KC_NLCK);
       }
       layer_off(3);
     }; // для NUMLOCK
}
return state;
}
