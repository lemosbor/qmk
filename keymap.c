#include QMK_KEYBOARD_H
#include "muse.h"

#define _QWERTY 0
#define _SERV 1
#define LT_PER LT(_SERV, TO(_SERV))

enum preonic_layers {
  _QWERTY,
  _SERV,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  SERV,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

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

/* Qwerty (KC_GRV — (тире —))
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
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  \
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, XP(JE,JEL),  KC_UP, KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_RALT, X(SNEK), LT_PER,   KC_SPC,  KC_SPC,  SERV,   KC_DEL, KC_LEFT, KC_DOWN,   KC_RGHT  \
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
 * | Упр  | МЛК  | Доп  | МПК  |   пробел           |ТО(0) | Вст  |   0  |   .  |право |
 * `-----------------------------------------------------------------------------------'
 */
 
[_SERV] = LAYOUT_preonic_grid( \
  [KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_NLCK, KC_PSLS, KC_PAST, KC_MINS, \
  KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_SLSH, KC_HOME, KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS,\
  MO(2), RGB_TOG, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_END, KC_PGDN, KC_P4, KC_P5, KC_P6, KC_PEQL,\
  KC_LSFT, KC_MS_L, C_MS_D, KC_MS_R, KC_NO, KC_BSLS, KC_LBRC, KC_RBRC, KC_P1, KC_P2, KC_P3, KC_PENT,\
  KC_LCTL, KC_BTN1, KC_LALT, C_BTN2, QWERTY, KC_SPC, KC_SPC, QWERTY, KC_INS, KC_P0, KC_PDOT, KC_RGHT \
)

};


bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
