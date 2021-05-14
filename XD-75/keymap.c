#include QMK_KEYBOARD_H //  qmk compile -kb xd75 -km leo
#include "par.c"
#include "keys.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
[L_OSNOVA] = LAYOUT_ortho_5x15( \
TD(KOP1), TD(VST1), TD(VYH), ZAP, TD(VOPRR), KAVYCH,  KC_EQL, KC_PPLS,  TD(SOHR), TD(SCLN),   SLESH,  TD(MINS),  TOCH,   TD(OSKOBT),  TD(ZSKOBT),  \
KC_F,  KC_BSLS,  KC_I,  KC_Y,   KC_F15,   TD(POISK), KC_7, KC_8, KC_9,  KC_RBRC,  KC_J,   KC_Z,  KC_L,  KC_D,  KC_GRV,  \
KC_S,  KC_E,  KC_A,  KC_O,  KC_Q,  KC_TAB,   KC_4, KC_5, KC_6,  KC_C,  KC_V, KC_T,  KC_N,  KC_K,  KC_W,  \
KC_LBRC,  KC_NUBS,  KC_X,  KC_U,  KC_F14,  KC_DEL, KC_1, KC_2, KC_3,  KC_H,  KC_G,  KC_P,  KC_R,  KC_M,  KC_B,  \
  TD(GIP),OTMENA,ALT_T(KC_F2),OSM(MOD_LSFT), LCTL_T(KC_SPC), KC_ENT,LT(L_DOP, KC_COMM),KC_0,TD(RU_AN), LT(L_DOP, KC_ENT), KC_SPC,   KC_UP,  KC_DOWN,  KC_LEFT,  KC_RGHT \
),
[L_DOP] = LAYOUT_ortho_5x15( \
C_INS,  S_INS,KC_RESET,   STEPE,  UMNO, UDAR,  KC_F10, KC_F11, KC_F12, KC_TRNS,  KC_TRNS,  MINMIN, KC_TRNS,  KC_TRNS, KC_TRNS, \
C(S(KC_F)), C(S(KC_BSLS)),  C(S(KC_I)),  C(S(KC_Y)),  KC_TRNS,  KC_TRNS,  KC_F7,  KC_F8,  KC_F9,  C(S(KC_RBRC)),  C(S(KC_J)),  KC_UP,  KC_DOWN,  KC_LEFT,  KC_RGHT, \
KC_6,      KC_4,     KC_2,     KC_0,        KC_8, KC_TRNS,  KC_F4,  KC_F5,  KC_F6,  KC_NUMLOCK,   KC_9,   KC_1,     KC_3,     KC_5,     KC_7, \
C(S(KC_LBRC)),  KC_TRNS,  MEH(KC_X),  KC_COMM, S(KC_6),  UD_STROK, KC_F1,  KC_F2,  KC_F3,  KC_PGUP,  KC_EQL,   KC_PPLS,     KC_PSLS,     KC_PMNS, KC_PAST, \
PS_1, PS_2,  PS_3,  PS_4,  PS_5,   A(KC_F11), KC_TRNS, C(KC_PGUP), C(KC_PGDN),   KC_TRNS,  G_SP, KC_PGUP,  KC_PGDN, C(KC_PGUP),  C(KC_PGDN) \
),
}; 

bool led_update_user(led_t led_state) { // зажечь светодиод если в положении НЕ КапсЛок
    if (led_state.caps_lock) {
        capslock_led_off();
    } else {
        capslock_led_on();
    }
    return false;
};