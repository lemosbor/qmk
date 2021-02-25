#include QMK_KEYBOARD_H //  qmk compile -kb xd75 -km leo
#include "keys.c"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
[L_OSNOVA] = LAYOUT_ortho_5x15( \
  TD(KOP1),      TD(VST1),     KC_COMM,     VOPR,   KAVYCH, KC_SCLN,     KC_7,   KC_8,   KC_9,           OSKOB,        ZSKOB,    KC_MINS, KC_DOT, SLESH,   TD(SOHR), \
  KC_C,          KC_X,         KC_U,        KC_GRV, KC_LBRC,TD(POISK),   KC_4,   KC_5,   KC_6,           TWZ,          KC_H,     KC_P,    KC_L,   KC_M,    KC_V, \
  KC_I,          KC_A,         KC_E,        KC_O,   KC_S,   KC_ENT,      KC_1,   KC_2,   KC_3,           KC_RBRC,      KC_K,     KC_N,    KC_T,   KC_W,    KC_R, \
  KC_BSLS,       RU_E,         KC_Q,        KC_Y,   KC_NUBS,KC_DEL,      KC_0,   KC_UP,LT(L_DOP, KC_PDOT),KC_F,        KC_G,     KC_D,    KC_B,   KC_Z,    KC_J, \
  CTL_T(KC_ESC),LGUI_T(KC_TAB),ALT_T(KC_F2),KC_BSPC,OSM(MOD_LSFT),KC_SPC,KC_LEFT,KC_DOWN,KC_RGHT,        KC_SPC,  SFT_T(OTMENA),TD(RU_AN),KC_HOME,TD(KONE),ALTTABB \
),
[L_DOP] = LAYOUT_ortho_5x15( \
  KC_TRNS,       KC_TRNS,      STEPE,       UMNO,     UDAR,    KC_TRNS, KC_F7,     KC_F8,       KC_F9,  KK_LBRC, KK_RBRC,    RU_TIR,   GRADU,  C(A(KC_DEL)),PS_1, \
  KC_NUMLOCK,    RU_TY,        KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_F4,     KC_F5,       KC_F6,  KC_TRNS, KC_TRNS,    KC_PSCR,  KC_TRNS,  KC_TRNS,   PS_2, \
  KC_TRNS,       KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_F1,     KC_F2,       KC_F3,  KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,   PS_3, \
  KC_TRNS,       KC_TRNS,      KC_TRNS,     KC_TRNS, A(KC_F11),UD_STROK,C(KC_PGUP),C(KC_PGDN),  KC_TRNS, KC_TRNS, KC_TRNS, C(S(KC_DEL)),KC_TRNS, KC_TRNS,   PS_4, \
  A(KC_F4),      KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,    G_SP, KC_F10,    KC_F11,      KC_F12,  G_SP,   KC_TRNS,    KC_TRNS,  KC_PGUP,  KC_PGDN,   PS_5 \
)
}; 

bool led_update_user(led_t led_state) { // зажечь светодиод если в положении НЕ КапсЛок
    if (led_state.caps_lock) {
        capslock_led_off();
    } else {
        capslock_led_on();
    }
    return false;
};
