#include QMK_KEYBOARD_H //  qmk compile -kb preonic/rev3 -km pri
#include "keymap_steno.h"
#include "par.c"
#define L_MUSIC 3 // слой 1 (сервисный)
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
  TD(KOP1),     TD(VST1),TD(VYH), ZAP,    VOPR, KAVYCH, KC_SCLN,  SLESH,  TD(MINS), TOCH, TD(OSKOBT),  TD(ZSKOBT), \
KC_F,  KC_BSLS,  KC_I, KC_Y ,   KC_F15,   TD(POISK),  KC_RBRC,  KC_J,   KC_Z,  KC_L,  KC_D,  KC_GRV,  \
KC_S,  KC_E,  KC_A,  KC_O,  KC_Q,  KC_TAB,   KC_C,  KC_V,  KC_T,  KC_N,  KC_K,  KC_W,  \
KC_LBRC,  KC_NUBS,  KC_X, KC_U ,  RU_E,  KC_DEL,    KC_H,  KC_G,  KC_P,  KC_R,  KC_M,  KC_B,  \
  TD(GIP),TD(RU_AN),ALT_T(KC_F2),OSM(MOD_LSFT),CTL_T(KC_SPC),  KC_ENT, TD(PLOVER), LT(L_DOP, KC_SPC), KC_UP, KC_DOWN,KC_LEFT,KC_RGHT \
),
[L_DOP] = LAYOUT_preonic_grid( \
  RGB_TOG,      RGB_MOD,       S(KC_7), S(KC_2),      S(KC_1),     S(KC_3),   KC_F10,  KC_F11,  KC_F12,   KC_PAST,   KC_PPLS, KC_EQL,  \
  KC_NUMLOCK,   KC_TRNS,        KC_TRNS,     KC_RESET,   KC_PSCR,  KC_TRNS, KC_F7,   KC_F8,   KC_F9,     KC_7,     KC_8,     KC_9, \
  KC_MUTE,      KC_VOLD,        KC_VOLU,     KC_MSTP,   KC_MNXT,  KC_TRNS, KC_F4,   KC_F5,   KC_F6,     KC_4,     KC_5,     KC_6, \
  TO(L_PLOVER),   KC_BRID,        KC_BRIU,     C(S(KC_ESC)),KC_TRNS,UD_STROK, KC_F1,   KC_F2,   KC_F3,     KC_1,     KC_2,     KC_3, \
  TO(L_MUSIC),     PS_1,           PS_2,        KC_TRNS, C(KC_PGUP),C(KC_PGDN),G_SP, KC_TRNS,  KC_PGUP,  KC_PDOT ,  KC_0,     KC_PGDN \
),
[L_PLOVER] = LAYOUT_preonic_grid(
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, \
  STN_N1,  STN_N2,  STN_A,   STN_O,  STN_ST1, ST_BOLT,  STN_NC ,STN_N5,  STN_N6,  STN_E,   STN_U,  STN_N9,   \
  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST2, ST_GEM,   STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR , \
  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_NA, KC_TRNS, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR , \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,KC_SPC,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS \
),
[L_MUSIC] = LAYOUT_preonic_grid( \
    KC_NO  ,  KC_NO ,  KC_NO ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_NO  ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    MU_TOG ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    MU_MOD,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    TO(L_OSNOVA),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO \
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