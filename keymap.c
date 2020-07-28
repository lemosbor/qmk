#include QMK_KEYBOARD_H
#include "process_unicode.h"

#define L_QWERTY 0
#define L_SERV 1

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    JE,
    JEL
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [JE]  = 0x0436, // ж
    [JEL]  = 0x0416, // Ж
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ВШ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Таб  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Капс |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Рег  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |вверх | Ввод |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Упр  | Окно | Доп  |   ~  |Lower |    пробел   |Raise | Удл  | лево | вниз |право |
 * `-----------------------------------------------------------------------------------'
 */
[L_QWERTY] = LAYOUT_preonic_grid( \
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
 * |  Ф9  |  Ф10 |  Ф11 |  Ф12 |      |   ё  |  нач | вверх|   7  |   8  |   9  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Мо(2)|  цвет| Мверх|      |      |      |  кон | вниз |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Рег  | Млево| Мвниз|Мправо|      |   \  |   {  |   ъ} |   1  |   2  |   3  | Ввод |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Упр  | МЛК  | Доп  | МПК  |   пробел           |ТО(0) |   ,  |   0  |   .  |право |
 * `-----------------------------------------------------------------------------------'
 */
 
[L_SERV] = LAYOUT_preonic_grid( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_NLCK, KC_PSLS, KC_PAST, KC_MINS, \
  KC_F9, KC_F10, KC_F11, KC_F12, X(SNEK), KC_SLSH, KC_HOME, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS,\
  KC_F9, RGB_TOG, KC_MS_U, RGB_MOD, KC_PASTE, KC_NO, KC_END, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_PEQL,\
  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_COPY, KC_BSLS, KC_LBRC, KC_RBRC, KC_P1, KC_P2, KC_P3, KC_PENT,\
  KC_LCTL, KC_BTN1, KC_LALT, KC_BTN2, TO(L_QWERTY), KC_SPC, KC_SPC, TO(L_QWERTY), KC_PCMM, KC_P0, KC_PDOT, KC_RGHT \
)

};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_C5, 8},
  {NOTE_E6, 4},
  {NOTE_D6, 16},
  {NOTE_G6, 8}
};

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif

void eeconfig_init_user(void) {

set_unicode_input_mode(UC_WINC);

}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case L_QWERTY:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_magenta(); rgblight_mode_noeeprom(1); }
        break;
    case L_SERV:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_red(); rgblight_mode_noeeprom(1); }
        break;
    }
  return state;
}