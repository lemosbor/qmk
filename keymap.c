#include QMK_KEYBOARD_H // компиляция по QMK
//#include "eeconfig.h"
//#include "preonic.h"
//#include "action_layer.h"
//#include "process_unicode.h" // для юникода
// #include "keymap_russian.h" // подгрузка русских букв  qmk compile -kb preonic/rev3 -km pri

#define L_OSNOVA 0 // слой 0 (основной)
#define L_SERV 1 // слой 1 (сервисный)


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
    WEMO // окно / окно+точка
};
uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий
void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий
void ql_reset(qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* Основа
 * ,-----------------------------------------------------------------------------------.
 * | Вых  |  ! ° |  " @ |  № # |  ; $ |  , % |  : ^ |  ? & | . *  | ( «  |  ) » |  ВШ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ТАБ  |   Й  |   Ц  |   У  |   К  |   Е  |   Н  |   Г  |   Ш  |   Щ  |   З  |   Х  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Р/А  |   Ф  |   Ы  |   В  |   А  |   П  |   Р  |   О  |   Л  |   Д  |   Ж  |   Э  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | РЕГ  |   Я  |   Ч  |   С  |   М  |   И  |   Т  |   Ь  |   Б  |   Ю  |   ↑  | ВВОД |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  | Окно | ДОП  |   —  |ФК/МОД|    пробел   |  -   |  УД  |   ←  |   ↓  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  TD(VYH),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  TD(TABB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  \
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_ENT,  \
  KC_LCTL, TD(WEMO), KC_RALT, KC_GRV, TD(PER_LAY),   KC_SPC,  KC_SPC,  KC_MINS,   KC_DEL, KC_LEFT, KC_DOWN,   KC_RGHT  \
),
/* сервисная
 * ,-----------------------------------------------------------------------------------.
 * |  Ф1  |  Ф2  |  Ф3  |  Ф4  |  Ф5  |  Ф6  |  Ф7  |  Ф8  |  ЦИФ |   /  |   *  |  ВШ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Ф9  |  Ф10 |  Ф11 |  Ф12 |      |  Ё   |  нач | вверх|   7  |   8  |   9  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |цвет р| цвет |М.верх|      |      |  вст |  кон | вниз |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | РЕГ  |М.лево|М.вниз|М.прав|      |   \  |   {  |   Ъ  |   1  |   2  |   3  | ВВОД |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  | М.ЛК | ДОП  | М.ПК |  ФК  |    пробел   |   -  |   ,  |   0  |   .  |право |
 * `-----------------------------------------------------------------------------------'
 */
[L_SERV] = LAYOUT_preonic_grid( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC, \
  KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_SLSH, KC_HOME, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS,\
  RGB_MOD, RGB_TOG, KC_MS_U, KC_NO, KC_NO, KC_INS, KC_END, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_EQL,\
  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_BSLS, KC_LBRC, KC_RBRC, KC_P1, KC_P2, KC_P3, KC_ENT,\
  KC_LCTL, KC_BTN1, KC_LALT, KC_BTN2, TD(PER_LAY), KC_SPC, KC_SPC, KC_MINS, KC_5, KC_P0, KC_PDOT, KC_RGHT \
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

void ql_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: // одиночное нажатие
            //tap_code(KC_QUOT);
            break;
        case SINGLE_HOLD: // одиночное удержание. Временное переключение слоя
            layer_on(L_SERV);
            break;
        case DOUBLE_TAP: // двойное нажатие удержание. Постоянное переключение слоя
            if (layer_state_is(L_SERV)) { // проверка не назначен ли данный слой уже                
                layer_off(L_SERV); // если установлен, то отключить
            } else {
                layer_on(L_SERV); // если не установлен, то включить
            }
            break;
    }
};

void ql_reset(qk_tap_dance_state_t *state, void *user_data) { // если клавиша была нажата, а теперь отпущена (то отключить слой)
    if (ql_tap_state.state == SINGLE_HOLD) { //при одиночном нажатии
        layer_off(L_SERV); // отключить слой
    }
    ql_tap_state.state = 0; // обнуление состояния
};

qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [PER_LAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275),
    [VVERH] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_HOME), // вверх или домой
    [VNIZ] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_END), // вниз или в конец
    [VYH] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)), // выход или альт+ф4
    [TABB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LALT(KC_TAB)), // таб или альт+таб https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
    [WEMO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_DOT)) // вин или эмодзи
};

layer_state_t layer_state_set_user(layer_state_t state) { //цветовая индикация переключения раскладок
    switch (get_highest_layer(state)) {
    case L_SERV:
        rgblight_setrgb (0xFF,  0x00, 0x00);
    case L_OSNOVA:
        rgblight_setrgb (0x00,  0x00, 0xFF);
    }
  return state;
};

//void rgb_matrix_indicators_user(void) { //индикация капса
    //if (host_keyboard_led_state().caps_lock) {
      //  rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
    //}
//}
//индикация сервисной раскладки