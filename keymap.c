#include QMK_KEYBOARD_H // компиляция по QMK
#include "process_unicode.h" // для юникода

#define L_OSNOVA 0 // слой 0 (основной)
#define L_SERV 1 // слой 1 (сервисный)

enum unicode_names { //названия юникодов
    BANG,
    IRONY,
    SNEK,
    JE,
    JEL
};

const uint32_t PROGMEM unicode_map[] = { // задание юникодов
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [JE]  = 0x0436, // ж
    [JEL]  = 0x0416, // Ж
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц

/* Основа
 * ,-----------------------------------------------------------------------------------.
 * | Вых  |  ! ° |  " @ |  № # |  ; $ |  , % |  : ^ |  ? & | . *  | ( «  |  ) » |  ВШ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Таб  |   Й  |   Ц  |   У  |   К  |   Е  |   Н  |   Г  |   Ш  |   Щ  |   З  |   Х  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Капс |   Ф  |   Ы  |   В  |   А  |   П  |   Р  |   О  |   Л  |   Д  |   Ж  |   Э  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Рег  |   Я  |   Ч  |   С  |   М  |   И  |   Т  |   Ь  |   Б  |   Ю  |   ↑  | Ввод |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Упр  | Окно | Доп  |   —  | Серв |    пробел   | Серв |  Удл |   ←  |   ↓  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  \
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_RALT, KC_GRV, MO(L_SERV),   KC_SPC,  KC_SPC,  TO(L_SERV),   KC_DEL, KC_LEFT, KC_DOWN,   KC_RGHT  \
),

/* сервисная
 * ,-----------------------------------------------------------------------------------.
 * |   Ф1 |   Ф2 |  Ф3  |   Ф4 |  Ф5  |  Ф6  |  Ф7  |  Ф8  |  ЦИФ |   /  |   *  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Ф9  |  Ф10 |  Ф11 |  Ф12 |      |   Ё  |  нач | вверх|   7  |   8  |   9  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Мо(2)|  цвет| Мверх|цвет р|музыка|свет  |  кон | вниз |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Рег  | Млево| Мвниз|Мправо|      |   \  |   {  |   Ъ  |   1  |   2  |   3  | Ввод |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Упр  | МЛК  | Доп  | МПК  |   пробел           |ТО(0) |   ,  |   0  |   .  |право |
 * `-----------------------------------------------------------------------------------'
 */
 
[L_SERV] = LAYOUT_preonic_grid( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_NLCK, KC_PSLS, KC_PAST, KC_MINS, \
  KC_F9, KC_F10, KC_F11, KC_F12, X(SNEK), KC_SLSH, KC_HOME, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS,\
  KC_F9, RGB_TOG, KC_MS_U, RGB_MOD, AU_TOG, BL_TOGG, KC_END, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_PEQL,\
  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_COPY, KC_BSLS, KC_LBRC, KC_RBRC, KC_P1, KC_P2, KC_P3, KC_PENT,\
  KC_LCTL, KC_BTN1, KC_LALT, KC_BTN2, TO(L_OSNOVA), KC_SPC, KC_SPC, TO(L_OSNOVA), KC_PCMM, KC_P0, KC_PDOT, KC_RGHT \
)

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
