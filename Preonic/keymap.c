#include QMK_KEYBOARD_H //  qmk compile -kb preonic/rev3 -km pri
#include "par.c"
#include "keys.c"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
[L_OSNOVA] = LAYOUT_preonic_grid( \
  TD(KOP1),      TD(VST1),      KC_COMM,     VOPR,     KAVYCH,   KC_SCLN, KC_EQL,  SLESH,   KC_MINS,   KC_DOT,   OSKOB,    ZSKOB, \
  KC_C,          KC_X,          KC_U,        KC_GRV,   KC_LBRC,  TD(POISK),KC_F,    KC_H,    KC_P,      KC_L,     KC_M,     KC_V, \
  KC_I,          KC_A,          KC_E,        KC_O,     KC_S,     KC_ENT,  KC_RBRC, KC_K,    KC_N,      KC_T,     KC_W,     KC_R, \
  SFT_T(KC_BSLS),RU_E,          KC_Q,        KC_Y,     KC_NUBS,  KC_DEL,  KC_UP,   KC_G,    KC_D,      KC_B,     KC_Z,     KC_J, \
  CTL_T(KC_ESC), LGUI_T(KC_TAB),ALT_T(KC_F2),KC_BSPC,  KC_SPC,   KC_LEFT, KC_DOWN,SFT_T(KC_RGHT),OSL(L_DOP),TD(RU_AN), OTMENA, ALTTABB \
),
[L_DOP] = LAYOUT_preonic_grid( \
  RGB_TOG,      RGB_MOD,        S(KC_5),     STEPE,     S(KC_2),  S(KC_4), KC_F10,  KC_F11,  KC_F12,    KC_PAST,  KK_LBRC,  KK_RBRC, \
  KC_NUMLOCK,   RU_TY,          KC_TRNS,     KC_TRNS,   KC_PSCR,  KC_TRNS, KC_F7,   KC_F8,   KC_F9,     KC_7,     KC_8,     KC_9, \
  KC_MUTE,      KC_VOLD,        KC_VOLU,     KC_MSTP,   KC_MNXT,  KC_TRNS, KC_F4,   KC_F5,   KC_F6,     KC_4,     KC_5,     KC_6, \
  KC_TRNS,      KC_BRID,        KC_BRIU,     C(S(KC_ESC)),KC_TRNS,KC_TRNS, KC_F1,   KC_F2,   KC_F3,     KC_1,     KC_2,     KC_3, \
  A(KC_F4),     PS_1,           KC_TRNS,     KC_TRNS,   G_SP,     KC_HOME, KC_PGDN, KC_END,  KC_TRNS,   KC_PDOT,  KC_0,     KC_TRNS \
)
}; 

void encoder_update_user(uint8_t index, bool clockwise) {  // действия знкодера
        switch(biton32(layer_state)){
          case 0: // на слое 0
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
            break;
            case 1: // на слое 1
                if (clockwise){
                    tap_code(KC_RGHT);
                } else{
                    tap_code(KC_LEFT);
                }
                break;
          }
};