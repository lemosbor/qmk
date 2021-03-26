#include QMK_KEYBOARD_H //  qmk compile -kb xd75 -km leo
#include "par.c"
#include "keys.c"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
[L_OSNOVA] = LAYOUT_ortho_5x15( \
TD(KOP1), TD(VST1), TD(VYH), KC_COMM, VOPR, KAVYCH,  KC_EQL, OTMENA,  TD(SOHR), KC_SCLN,   SLESH,  TD(MINS),  KC_DOT,   TD(OSKOBT),  TD(ZSKOBT),  \
KC_F,  KC_NUBS,  KC_I,  KC_Q,   KC_F15,   TD(POISK), KC_7, KC_8, KC_9,  KC_RBRC,  KC_V,   KC_J,  KC_L,  KC_D,  KC_GRV,  \
KC_S,  KC_E,  KC_A,  KC_O,  KC_Y,  KC_TAB,   KC_4, KC_5, KC_6,  KC_H,  KC_P,  KC_T,  KC_N,  KC_K,  KC_W,  \
KC_LBRC,  KC_BSLS,  KC_X,  KC_U,  RU_E,  KC_DEL, KC_1, KC_2, KC_3,  KC_C,  KC_Z,  KC_G,  KC_R,  KC_M,  KC_B,  \
ALTTABB,TD(VYDEL),ALT_T(KC_F2),OSM(MOD_LSFT),CTL_T(KC_SPC),  KC_ENT,LT(L_DOP, KC_PDOT),KC_0,TD(RU_AN), KC_BSPC, KC_SPC,   KC_UP,  KC_DOWN,  KC_LEFT,  KC_RGHT \
),
[L_DOP] = LAYOUT_ortho_5x15( \
KC_TRNS,  KC_TRNS,KC_TRNS,   STEPE,  UMNO, UDAR,  KC_F10, KC_F11, KC_F12, KC_TRNS,  KC_TRNS,  RU_TIR, KC_PAST,  C(A(KC_DEL)), PS_1, \
KC_NUMLOCK, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F7,  KC_F8,  KC_F9,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  PS_2, \
KC_RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F4,  KC_F5,  KC_F6,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  PS_3, \
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  UD_STROK, KC_F1,  KC_F2,  KC_F3,  KC_PGUP,  KC_TRNS,  C(S(KC_DEL)), KC_TRNS,  KC_TRNS,  PS_4, \
KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   A(KC_F11), KC_TRNS, C(KC_PGUP), C(KC_PGDN),   KC_PGDN,  G_SP, KC_TRNS,  KC_TRNS,  KC_TRNS,  PS_5 \
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
