#include QMK_KEYBOARD_H //  qmk compile -kb xd75 -km leo
#include "keymap_steno.h"
#include "par.c"
#define L_PLOVER 2
#include "keys.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
[L_OSNOVA] = LAYOUT_ortho_5x15( \
TD(KOP1), TD(VST1), TD(VYH), KC_COMM, VOPR, KAVYCH,  KC_EQL, OTMENA,  TD(SOHR), KC_SCLN,   SLESH,  TD(MINS),  KC_DOT,   TD(OSKOBT),  TD(ZSKOBT),  \
KC_F,  KC_NUBS,  KC_I,  KC_U,   KC_F15,   TD(POISK), KC_7, KC_8, KC_9,  KC_RBRC,  KC_C,   KC_J,  KC_L,  KC_D,  KC_GRV,  \
KC_S,  KC_E,  KC_A,  KC_O,  KC_Y,  KC_TAB,   KC_4, KC_5, KC_6,  KC_V,  KC_Z, KC_T,  KC_N,  KC_K,  KC_W,  \
KC_LBRC,  KC_BSLS,  KC_X,  KC_Q,  RU_E,  KC_DEL, KC_1, KC_2, KC_3,  KC_H,  KC_P,  KC_G,  KC_R,  KC_M,  KC_B,  \
ALTTABB,TD(VYDEL),ALT_T(KC_F2),OSM(MOD_LSFT),CTL_T(KC_SPC),  KC_ENT,LT(L_DOP, KC_PDOT),KC_0,TD(RU_AN), KC_BSPC, KC_SPC,   KC_UP,  KC_DOWN,  KC_LEFT,  KC_RGHT \
),
[L_DOP] = LAYOUT_ortho_5x15( \
KC_TRNS,  KC_TRNS,KC_TRNS,   STEPE,  UMNO, UDAR,  KC_F10, KC_F11, KC_F12, KC_TRNS,  KC_TRNS,  RU_TIR, KC_PAST,  C(A(KC_DEL)), PS_1, \
KC_NUMLOCK, KC_TRNS,  KC_TRNS,  KC_RESET,  KC_TRNS,  KC_TRNS,  KC_F7,  KC_F8,  KC_F9,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  PS_2, \
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F4,  KC_F5,  KC_F6,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  PS_3, \
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  UD_STROK, KC_F1,  KC_F2,  KC_F3,  KC_PGUP,  KC_TRNS,  C(S(KC_DEL)), KC_TRNS,  KC_TRNS,  PS_4, \
KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   A(KC_F11), KC_TRNS, C(KC_PGUP), C(KC_PGDN),   KC_PGDN,  G_SP, KC_TRNS,  KC_TRNS,  KC_TRNS,  PS_5 \
),
[L_PLOVER] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, STN_N3,  STN_N4, STN_NA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 				XXXXXXX, XXXXXXX, XXXXXXX, STN_N7,  STN_N8, XXXXXXX, \
  STN_N1,  STN_N2,  STN_A,   STN_O,  TO(L_OSNOVA),STN_NB, KC_7, KC_8, KC_9,		 	STN_NC ,STN_N5,  STN_N6,  STN_E,   STN_U,  STN_N9,   \
  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST2, STN_FN, KC_4, KC_5, KC_6,  			 STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR , \
  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST1, XXXXXXX, KC_1, KC_2, KC_3,			STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR , \
  XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, XXXXXXX,KC_0,TD(RU_AN),			XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2 \
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