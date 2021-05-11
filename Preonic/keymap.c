#include QMK_KEYBOARD_H //  qmk compile -kb preonic/rev3 -km pri
#include "par.c"
#define L_MUSIC 2 // слой 1 (сервисный)
#include "keys.c"

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
  TD(KOP1),     TD(VST1),TD(VYH), ZAP,   TD(VOPRR), KAVYCH, TD(SCLN),  SLESH,  TD(MINS), TOCH, TD(OSKOBT),  TD(ZSKOBT), \
KC_F,  KC_BSLS,  KC_I, KC_Y ,   KC_F15,   TD(POISK),  KC_RBRC,  KC_J,   KC_Z,  KC_L,  KC_D,  KC_GRV,  \
KC_S,  KC_E,  KC_A,  KC_O,  KC_Q,  KC_TAB,   KC_C,  KC_V,  KC_T,  KC_N,  KC_K,  KC_W,  \
KC_LBRC,  KC_NUBS,  KC_X, KC_U ,  KC_F14,  KC_DEL,    KC_H,  KC_G,  KC_P,  KC_R,  KC_M,  KC_B,  \
  TD(GIP),OTMENA,ALT_T(KC_F2),OSM(MOD_LSFT),LCTL_T(KC_SPC),  KC_ENT, TD(RU_AN), LT(L_DOP, KC_SPC), KC_UP, KC_DOWN,KC_LEFT,KC_RGHT \
),
[L_DOP] = LAYOUT_preonic_grid( \
  C_INS,      S_INS,       KC_RESET, KC_TRNS,   G_NOM,   G_PARA,   RGB_TOG,  RGB_MOD,  KC_VOLD,   KC_VOLU,   KC_BRID, KC_BRIU,  \
  KC_F1, KC_F2,     KC_F3,     KC_F4,   KC_F5,  KC_F6, KC_F7,   KC_F8,   KC_F9,     KC_F10,     KC_F11,     KC_F12, \
  KC_6,      KC_4,     KC_2,     KC_0,   KC_8,  KC_TRNS, KC_NUMLOCK,   KC_9,   KC_1,     KC_3,     KC_5,     KC_7, \
  KC_MUTE,   KC_TRNS,        MEH(KC_A),     KC_COMM,S(KC_6),UD_STROK, KC_TRNS,   KC_EQL,   KC_PPLS,     KC_PSLS,     KC_PMNS,     KC_PAST, \
  TO(L_MUSIC),     PS_1,           PS_2,        PS_3, KC_TRNS,KC_TRNS,G_SP, KC_TRNS,  KC_PGUP,  KC_PGDN ,  C(KC_PGUP),     C(KC_PGDN) \
),
[L_MUSIC] = LAYOUT_preonic_grid( \
    MU_TOG  ,  MU_MOD ,  TO(L_OSNOVA) ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_NO  ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_NO ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO \
),
}; 

void encoder_update_user(uint8_t index, bool clockwise) {  // действия знкодера
        switch(biton32(layer_state)){
          case 0: // на слое 0
            if (clockwise) {
                tap_code(KC_DOWN); //KC_MS_WH_DOWN
            } else {
                tap_code(KC_UP); //KC_MS_WH_UP
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