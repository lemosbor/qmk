#include QMK_KEYBOARD_H //  qmk compile -kb preonic/rev3 -km pri
#include "par.c"
#include "keys.c"
#define L_MUSIC 2 // слой 1 (сервисный)

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case 0:
    case 1:
      return false;
    default:
      return true;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц    
[L_OSNOVA] = LAYOUT_preonic_grid( \
  TD(KOP1),     TD(VST1),TD(VYH), KC_COMM,    VOPR, KAVYCH, KC_SCLN,       SLESH,     TD(MINS),KC_DOT, TD(OSKOBT),  TD(ZSKOBT), \
KC_F,  KC_NUBS,  KC_I,  KC_Q,   KC_F15,   TD(POISK),  KC_RBRC,  KC_V,   KC_J,  KC_L,  KC_D,  KC_GRV,  \
KC_S,  KC_E,  KC_A,  KC_O,  KC_Y,  KC_TAB,   KC_H,  KC_P,  KC_T,  KC_N,  KC_K,  KC_W,  \
KC_LBRC,  KC_BSLS,  KC_X,  KC_U,  RU_E,  KC_DEL,    KC_C,  KC_Z,  KC_G,  KC_R,  KC_M,  KC_B,  \
  ALTTABB,TD(RU_AN),ALT_T(KC_F2),OSM(MOD_LSFT),CTL_T(KC_SPC),  KC_ENT,  LT(L_DOP, KC_BSPC),KC_SPC, KC_UP, KC_DOWN,KC_LEFT,KC_RGHT \
),
[L_DOP] = LAYOUT_preonic_grid( \
  RGB_TOG,      RGB_MOD,       S(KC_4), S(KC_5),      S(KC_7),     S(KC_2),   KC_F10,  KC_F11,  KC_F12,   KC_PAST,   KC_PPLS, KC_EQL,  \
  KC_NUMLOCK,   KC_TRNS,        KC_TRNS,     KC_RESET,   KC_PSCR,  KC_TRNS, KC_F7,   KC_F8,   KC_F9,     KC_7,     KC_8,     KC_9, \
  KC_MUTE,      KC_VOLD,        KC_VOLU,     KC_MSTP,   KC_MNXT,  KC_TRNS, KC_F4,   KC_F5,   KC_F6,     KC_4,     KC_5,     KC_6, \
  KC_TRNS,      KC_BRID,        KC_BRIU,     C(S(KC_ESC)),KC_TRNS,UD_STROK, KC_F1,   KC_F2,   KC_F3,     KC_1,     KC_2,     KC_3, \
  TO(L_MUSIC),     PS_1,           PS_2,        KC_TRNS, C(KC_PGUP),C(KC_PGDN),KC_TRNS, G_SP,  KC_PGUP,   KC_PGDN,  KC_0,     KC_PDOT \
),
[L_MUSIC] = LAYOUT_preonic_grid( \
    KC_NO  ,  KC_NO ,  KC_NO ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_NO  ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    MU_TOG ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    MU_MOD,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    TO(L_OSNOVA),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO \
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
            case 2: // на слое 1
                if (clockwise){
                    tap_code(KC_DOWN);
                } else{
                    tap_code(KC_UP);
                }
                break;
          }
};
