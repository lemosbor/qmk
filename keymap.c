#include QMK_KEYBOARD_H // компиляция по QMK
#include "process_unicode.h" // для юникода

#define L_OSNOVA 0 // слой 0 (основной)
#define L_SERV 1 // слой 1 (сервисный)

enum custom_keycodes {
    E_2HEART //два сердца
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case E_2HEART:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("D83D+DC95")); //ввод кода через альт 
        }
        return false;
    }
    return true;
};

enum unicode_names { //объявление юникодов
    BANG = 0,
    IRONY,
    SNEK,
    JE,
    JEL
};

const uint32_t PROGMEM unicode_map[] = { // определение юникодов
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [JE]  = 0x0436, // ж
    [JEL]  = 0x0416 // Ж  
};
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
    VNIZ // кнопка вниз
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
 * | УПР  | Окно | ДОП  |   —  |  ФК  |    пробел   |  ФК  |  УД  |   ←  |   ↓  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  \
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(VVERH), KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_RALT, KC_GRV, TD(PER_LAY),   KC_SPC,  KC_SPC,  TO(L_SERV),   KC_DEL, KC_LEFT, TD(VNIZ),   KC_RGHT  \
),
/* сервисная
 * ,-----------------------------------------------------------------------------------.
 * |   Ф1 |   Ф2 |  Ф3  |   Ф4 |  Ф5  |  Ф6  |  Ф7  |  Ф8  |  ЦИФ |   /  |   *  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Ф9  |  Ф10 |  Ф11 |  Ф12 | SNEK |   Ё  |  серд| вверх|   7  |   8  |   9  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Мо(2)|  цвет| Мверх|цвет р|музыка|свет  |  кон | вниз |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | РЕГ  | Млево| Мвниз|Мправо|      |   \  |   {  |   Ъ  |   1  |   2  |   3  | ВВОД |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  | МЛК  | ДОП  | МПК  |   пробел           |ТО(0) |   ,  |   0  |   .  |право |
 * `-----------------------------------------------------------------------------------'
 */
[L_SERV] = LAYOUT_preonic_grid( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_NLCK, KC_PSLS, KC_PAST, KC_MINS, \
  KC_F9, KC_F10, KC_F11, KC_F12, X(SNEK), KC_SLSH, E_2HEART, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS,\
  KC_F9, RGB_TOG, KC_MS_U, RGB_MOD, AU_TOG, BL_TOGG, KC_END, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_PEQL,\
  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_COPY, KC_BSLS, KC_LBRC, KC_RBRC, KC_P1, KC_P2, KC_P3, KC_PENT,\
  KC_LCTL, KC_BTN1, KC_LALT, KC_BTN2, TO(L_OSNOVA), KC_SPC, KC_SPC, TO(L_OSNOVA), KC_PCMM, KC_P0, KC_PDOT, KC_RGHT \
)
};

uint8_t cur_dance(qk_tap_dance_state_t *state) { // определение состояния двойного нажатия
    if (state->count == 1) { //если нажата один раз
        if (!state->pressed) return SINGLE_TAP; // если не удерживается, то Одиночное нажатие
        else return SINGLE_HOLD; // иначе Одиночное удержание
    } else if (state->count == 2) return DOUBLE_TAP; // если нажата два раза, то Двойное нажатие
    else return 8; // магическое число на будущее
}
static tap ql_tap_state = { // Инициализация двойного нажатия
    .is_press_action = true,
    .state = 0 // обнуление состояния
};

void ql_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: // одиночное нажатие
            tap_code(KC_QUOT);
            break;
        case SINGLE_HOLD: // одиночное удержание. Временное переключение слоя
            layer_on(_MY_LAYER); 
            break;
        case DOUBLE_TAP: // двойное нажатие удержание. Постоянное переключение слоя
            if (layer_state_is(L_SERV)) { // проверка не назначен ли данный слой уже                
                layer_off(L_SERV); // если установлен, то отключить
            } else {
                layer_on(L_SERV); // если не установлен, то включить
            }
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) { // если клавиша была нажата, а теперь отпущена (то отключить слой)
    if (ql_tap_state.state == SINGLE_HOLD) { //при одиночном нажатии
        layer_off(L_SERV); // отключить слой
    }
    ql_tap_state.state = 0; // обнуление состояния
}

qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [PER_LAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275),
    [VVERH] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_HOME), // вверх или домой
    [VNIZ] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_END) // вниз или в конец
};

layer_state_t layer_state_set_user(layer_state_t state) { //цветовая индикация переключения раскладок
    switch (get_highest_layer(state)) {
    case L_OSNOVA:
        rgblight_setrgb (0x00,  0x00, 0xFF);
    case L_SERV:
        rgblight_setrgb (0xFF,  0x00, 0x00);
    }
  return state;
}

void rgb_matrix_indicators_user(void) [ //индикация капса
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(i, r, g, b);
    }
}
