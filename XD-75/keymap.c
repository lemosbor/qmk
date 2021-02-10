#include QMK_KEYBOARD_H //  qmk compile -kb xd75 -km leo

#define L_OSNOVA 0 // слой 0 (основной)
#define L_DOP 1 // слой 1 (сервисный)

// функция подмены вернего регистра
#define REG_R(kn1, s1, kn2, s2) \
if (record->event.pressed) { \
  if (shift_held) { \
      if (s2 == 0) { \
        unregister_code(KC_LSFT); \
        tap_code16(kn2); \
      } else { \
        tap_code16(kn2); \
        unregister_code(KC_LSFT); \
      } \
  } else { \
      if (s1 == 0) { \
        tap_code16(kn1); \
      } else { \
        register_code(KC_LSFT); \
        tap_code16(kn1); \
        unregister_code(KC_LSFT); \
      } \
    } \
} \
return false;

#define COD(code) \
if (record->event.pressed) { \
        SEND_STRING(code); \
      } \
      break; \
return false;

// горячие клавиши в одну
#define C_INS C(KC_INS)
#define ALTBS A(KC_BSPC)
#define ALTYY A(KC_P2)
#define S_INS S(KC_INS)
#define C_PGUP C(KC_PGUP)
#define C_PGDN C(KC_PGDN)
#define C_ENT C(KC_ENT)
#define C_X C(KC_X)  // могут не корректно идентифицироваться
#define C_S C(KC_S)
#define C_Z C(KC_Z)
#define C_Y C(KC_Y)
#define C_F C(KC_F)
#define A_TAB A(KC_TAB)
#define C_BS C(KC_BSPC)
#define S_SCLN S(KC_SCLN)
#define S_4 S(KC_4)
#define S_6 S(KC_6)
#define S_7 S(KC_7)
#define S_9 S(KC_9)
#define S_0 S(KC_0)
#define S_QUOT S(KC_QUOT)
#define CAD C(A(KC_DEL))
#define S_COMM G_COMM 
#define S_DOT G_DOT 
#define BUKTZ comb_BUKTZ

#define OKAV S(KC_9) // поменять на открытую и закрытую кавычки
#define ZKAV S(KC_0)

bool shift_held = false; // обнуляем индикатор зажатого РЕГ

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    VYH, // Вых / альт+Ф4
    TABB, // таб / альт+таб
    POISK,
    WEMO, // окно / окно+точка
    RU_AN, // кнопка Р/А
};

enum custom_keycodes {      
  KOP1 = SAFE_RANGE,
  VST1,
  ZAP,
  TOCH,
  VOPR,
  ZVEZD,
  SLESH,
  KAVYCH,
  PLUS,
  OSKOB,
  ZSKOB,
  DCC_1,
  DCC_2,
  OTMENA,
  SOHR,
  PS_1,
  RU_E,
  RU_TY,
  KK_LBRC,
  KK_RBRC,
  UDAR,
  G_COMM, // <
  G_DOT, // >
  G_SP, // неразрывный пробел
  
}; 

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_1)), // ё RU_E
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_0)), // Ё
    },
    {
    SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_4)), // ъ RU_TY
    SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_4)), // Ъ
    },
    {
     SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_1)), // [ KK_LBRC
      SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_3)), // { 
    },
    {
     SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_3)), // ] KK_RBRC
      SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_5)), // }
    },
    {
     SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // ` UDAR
SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_7)SS_TAP(X_KP_6)SS_TAP(X_KP_9)), // ударение
    },
};

enum combo_events { // обозначение комбо-команд
comb_TOCH,
comb_ZAP,
comb_TZ,
comb_DT,
comb_DEF,
comb_TIRE,
comb_VOS,
comb_VOP,
comb_DOP,
comb_REG1,
comb_REG2,
comb_PROB,
comb_NACH,
comb_KON,
comb_LEV,
comb_PRAV,
comb_VERH,
comb_VNIZ,
comb_VSH,
comb_VVOD,
comb_UDL,
comb_TAB,
comb_VIH,
comb_KOP1,
comb_VST1,
comb_UPR1,
comb_OTM,
comb_N1,
comb_N2,
comb_N3,
comb_N4,
comb_N5,
comb_N6,
comb_N7,
comb_N8,
comb_N9,
comb_N0,
comb_VSH2,
comb_INS,
comb_VYR,
comb_PER1,
comb_PER2,
comb_OCH,
comb_VVOD2,
comb_PER3,
comb_SOYI,
comb_BUKTZ,
comb_ZSCOB,
comb_OSCOB,
comb_OKAV,
comb_ZKAV,
comb_KAV, 
comb_N_ZAP,
comb_N_TOCH,
comb_N_DEL,
comb_N_UMN,
comb_N_MIN,
comb_N_PLUS,
comb_N_OSK,
comb_N_ZSK,
comb_N_RAV,
comb_N_DT,
comb_N_TZ,
comb_N_DOL,
comb_N_STEP,
comb_N_MEN,
comb_N_BOL,
comb_N_KAV,
comb_N_AND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* ,-----------------------------------------------------------------------------------.
 * | КОП  | ВСТ  |  ,%# |  ;:₽ |  ?!& |  "'  |        /\| |  +=  | -_—  | .$   | («[{ | )»]} | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   C  |   X  |   U  |   ~  |   [  |  ВЫХ |        *@^  |   H  |   P  |   L  |   M  |   J  |счгчгшфуiaeiae
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   I  |   A  |   E  |   O  |   S  |  ТАБ |          ]  |   K  |   N  |   T  |   W  |   R  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   /  |      |   Q  |   Y  |   \  |  Б/Ц |          F  |   G  |   D  |   B  |   V  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | УПР  | РЕГ  | ДОП  |  ГИП | ВВОД |  УД  |         ВШ  |пробел|  Р/А |  ОТМ |  ←   |   →  |
 * `-----------------------------------------------------------------------------------'
ц ь у ч ш ъ х п л м й
и а е о с щ к н т в р
э ё ы я ю ф г д б ж з
 */
[L_OSNOVA] = LAYOUT_ortho_5x15( \
  KOP1,        VST1,       ZAP,         VOPR,     KAVYCH,  KC_SCLN,  ZVEZD,   SLESH,  OSKOB,    ZSKOB,      PLUS,    KC_MINS,  TOCH,    KC_DEL,  SOHR, \
  KC_C,        KC_X,       KC_U,        KC_GRV,   KC_LBRC, TD(VYH),  KC_7,    KC_8,   KC_9,     KC_BSPC,    KC_H,    KC_P,     KC_L,    KC_M,    KC_J, \
  KC_I,        KC_A,       KC_E,        KC_O,     KC_S, KC_TAB, KC_4,    KC_5,   KC_6,     KC_RBRC,    KC_K,    KC_N,     KC_T,    KC_W,    KC_R, \
  KC_BSLS,     SFT_T(RU_E),     KC_Q,        KC_Y,     KC_NUBS, KC_UP,    KC_1,    KC_2,   KC_3,     KC_F,       KC_G,    KC_D,     KC_B,    KC_V,    KC_Z, \
  KC_LCTL,     KC_LSFT,    ALT_T(KC_F2),KC_ENT,   KC_LEFT, KC_DOWN,  KC_RGHT, KC_0,   TD(WEMO), OSL(L_DOP), KC_SPC,  TD(RU_AN),OTMENA,  TD(POISK), TD(TABB) \
),
[L_DOP] = LAYOUT_ortho_5x15( \
  KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,  UDAR, KC_TRNS, KC_F10, KC_F11, KK_LBRC,  KK_RBRC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  CAD,  KC_TRNS, \
  PS_1,        RU_TY,      KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F7,  KC_F8,  KC_F9,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
  KC_NUMLOCK,  KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_F4,  KC_F5,  KC_F6,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
  S_COMM,      S_DOT,      KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_PGUP,    KC_F1,  KC_F2,  KC_F3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
  KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_HOME,  KC_PGDN,    KC_END, KC_TRNS, KC_TRNS,  KC_TRNS,  G_SP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS \
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

// задаем сочитание клавиш (комбо)
const uint16_t PROGMEM TOCH_combo[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM ZAP_combo[] = {KC_U, KC_GRV, COMBO_END};
const uint16_t PROGMEM TZ_combo[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM DT_combo[] = {KC_O, KC_T, COMBO_END};
const uint16_t PROGMEM DEF_combo[] = {KC_A, KC_W, COMBO_END};
const uint16_t PROGMEM TIRE_combo[] = {KC_I, KC_R, COMBO_END};
const uint16_t PROGMEM VOS_combo[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM VOP_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM REG1_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM REG2_combo[] = {KC_GRV, KC_S, COMBO_END};
const uint16_t PROGMEM PROB_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM NACH_combo[] = {KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM KON_combo[] = {KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM LEV_combo[] = {KC_W, KC_T, COMBO_END};
const uint16_t PROGMEM PRAV_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM VERH_combo[] = {KC_L, KC_M, COMBO_END};
const uint16_t PROGMEM VNIZ_combo[] = {KC_B, KC_V, COMBO_END};
const uint16_t PROGMEM VSH_combo[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM VVOD_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM UDL_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM TAB_combo[] = {KC_N, KC_R, COMBO_END};
const uint16_t PROGMEM VIH_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM KOP1_combo[] = {KC_X, KC_U, COMBO_END};
const uint16_t PROGMEM VST1_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM VYR_combo[] = {KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM UPR1_combo[] = {KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM OTM_combo[] = {KC_C, KC_GRV, COMBO_END};
const uint16_t PROGMEM N1_combo[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM N2_combo[] = {KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM N3_combo[] = {KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM N4_combo[] = {KC_Y, KC_R, COMBO_END};
const uint16_t PROGMEM N5_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM N6_combo[] = {KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM N7_combo[] = {KC_Y, KC_L, COMBO_END};
const uint16_t PROGMEM N8_combo[] = {KC_Y, KC_M, COMBO_END};
const uint16_t PROGMEM N9_combo[] = {KC_Y, KC_J, COMBO_END};
const uint16_t PROGMEM N0_combo[] = {KC_Y, KC_K, COMBO_END};
const uint16_t PROGMEM VSH2_combo[] = {KC_EQL, KCC_YO, COMBO_END};
const uint16_t PROGMEM INS_combo[] = {KC_X, KC_E, COMBO_END};
const uint16_t PROGMEM PER1_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM PER2_combo[] = {KC_D, KC_W, COMBO_END};
const uint16_t PROGMEM OCH_combo[] = {KC_Q, KC_Y, COMBO_END};
const uint16_t PROGMEM VVOD2_combo[] = {KC_O, KC_S, COMBO_END};
const uint16_t PROGMEM PER3_combo[] = {KC_N, KC_V, COMBO_END};
const uint16_t PROGMEM SOYI_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM BUKTZ_combo[] = {KC_I, KC_X, COMBO_END};
const uint16_t PROGMEM DOP_combo[] = {KC_D, KC_T, COMBO_END};
const uint16_t PROGMEM ZSCOB_combo[] = {KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM OSCOB_combo[] = {KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM OKAV_combo[] = {KC_C, KC_P, COMBO_END};
const uint16_t PROGMEM ZKAV_combo[] = {KC_GRV, KC_J, COMBO_END};
const uint16_t PROGMEM KAV_combo[] = {KC_GRV, KC_LBRC, COMBO_END};
const uint16_t PROGMEM N_ZAP_combo[] = {KC_1, KC_5, COMBO_END};
const uint16_t PROGMEM N_TOCH_combo[] = {KC_5, KC_3, COMBO_END};
const uint16_t PROGMEM N_DEL_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM N_UMN_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM N_MIN_combo[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM N_PLUS_combo[] = {KC_6, KC_5, COMBO_END};
const uint16_t PROGMEM N_OSK_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM N_ZSK_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM N_RAV_combo[] = {KC_4, KC_6, COMBO_END};
const uint16_t PROGMEM N_DT_combo[] = {KC_4, KC_8, COMBO_END};
const uint16_t PROGMEM N_TZ_combo[] = {KC_8, KC_6, COMBO_END};
const uint16_t PROGMEM N_DOL_combo[] = {KC_4, KC_2, COMBO_END};
const uint16_t PROGMEM N_STEP_combo[] = {KC_1, KC_8, COMBO_END};
const uint16_t PROGMEM N_MEN_combo[] = {KC_1, KC_0, COMBO_END};
const uint16_t PROGMEM N_BOL_combo[] = {KC_0, KC_3, COMBO_END};
const uint16_t PROGMEM N_KAV_combo[] = {KC_7, KC_9, COMBO_END};
const uint16_t PROGMEM N_AND_combo[] = {KC_2, KC_6, COMBO_END};
//связываем комбо с функциональными клавишами и действиями
combo_t key_combos[COMBO_COUNT] = { 
[comb_TOCH] = COMBO_ACTION(TOCH_combo),
[comb_ZAP] = COMBO_ACTION(ZAP_combo),
[comb_TZ] = COMBO_ACTION(TZ_combo),
[comb_DT] = COMBO_ACTION(DT_combo),
[comb_DEF] = COMBO(DEF_combo, KC_MINS),
[comb_TIRE] = COMBO_ACTION(TIRE_combo),
[comb_VOS] = COMBO_ACTION(VOS_combo),
[comb_VOP] = COMBO_ACTION(VOP_combo),
[comb_REG1] = COMBO_ACTION(REG1_combo),  
[comb_REG2] = COMBO_ACTION(REG2_combo),
[comb_PROB] = COMBO(PROB_combo, KC_SPC),
[comb_NACH] = COMBO(NACH_combo, KC_HOME),
[comb_KON] = COMBO(KON_combo, KC_END),
[comb_LEV] = COMBO(LEV_combo, KC_LEFT),
[comb_PRAV] = COMBO(PRAV_combo, KC_RGHT),
[comb_VERH] = COMBO(VERH_combo, KC_UP),
[comb_VNIZ] = COMBO(VNIZ_combo, KC_DOWN),
[comb_VSH] = COMBO(VSH_combo, KC_BSPC),
[comb_VSH2] = COMBO(VSH2_combo, C_BS),
[comb_VVOD] = COMBO(VVOD_combo, KC_ENT),
[comb_VVOD2] = COMBO(VVOD2_combo, C_ENT),
[comb_UDL] = COMBO(UDL_combo, KC_DEL),
[comb_TAB] = COMBO(TAB_combo, KC_TAB),
[comb_VIH] = COMBO(VIH_combo, KC_ESC),
[comb_KOP1] = COMBO(KOP1_combo, C_INS),
[comb_VST1] = COMBO(VST1_combo, S_INS),
[comb_VYR] = COMBO(VYR_combo, C_X),
[comb_UPR1] = COMBO_ACTION(UPR1_combo),
[comb_OTM] = COMBO(OTM_combo, OTMENA),
[comb_N1] = COMBO(N1_combo, KC_P1),
[comb_N2] = COMBO(N2_combo, KC_P2),
[comb_N3] = COMBO(N3_combo, KC_P3),
[comb_N4] = COMBO(N4_combo, KC_P4),
[comb_N5] = COMBO(N5_combo, KC_P5),
[comb_N6] = COMBO(N6_combo, KC_P6),
[comb_N7] = COMBO(N7_combo, KC_P7),
[comb_N8] = COMBO(N8_combo, KC_P8),
[comb_N9] = COMBO(N9_combo, KC_P9),
[comb_N0] = COMBO(N0_combo, KC_P0),
[comb_INS] = COMBO(INS_combo, KC_INS),
[comb_PER1] = COMBO_ACTION(PER1_combo),
[comb_PER2] = COMBO(PER2_combo, C_PGDN),
[comb_PER3] = COMBO(PER3_combo, C_PGUP),
[comb_OCH] = COMBO_ACTION(OCH_combo),
[comb_SOYI] = COMBO_ACTION(SOYI_combo),
[comb_BUKTZ] = COMBO_ACTION(BUKTZ_combo),
[comb_DOP] = COMBO_ACTION(DOP_combo),
[comb_OSCOB] = COMBO(OSCOB_combo, S_9),
[comb_ZSCOB] = COMBO_ACTION(ZSCOB_combo),
[comb_OKAV] = COMBO(OKAV_combo, OKAV),
[comb_ZKAV] = COMBO_ACTION(ZKAV_combo),
[comb_KAV] = COMBO(KAV_combo, S_QUOT),
[comb_N_ZAP] = COMBO(N_ZAP_combo, KC_COMM),
[comb_N_TOCH] = COMBO(N_TOCH_combo, KC_PDOT),
[comb_N_DEL] = COMBO(N_DEL_combo, KC_PSLS),
[comb_N_UMN] = COMBO(N_UMN_combo, KC_PAST),
[comb_N_MIN] = COMBO(N_MIN_combo, KC_PMNS),
[comb_N_PLUS] = COMBO(N_PLUS_combo, KC_PPLS),
[comb_N_OSK] = COMBO(N_OSK_combo, S_9),
[comb_N_ZSK] = COMBO(N_ZSK_combo, S_0),
[comb_N_RAV] = COMBO(N_RAV_combo, KC_EQL),
[comb_N_DT] = COMBO(N_DT_combo, S_SCLN),
[comb_N_TZ] = COMBO(N_TZ_combo, KC_SCLN),
[comb_N_DOL] = COMBO(N_DOL_combo, S_4),
[comb_N_STEP] = COMBO(N_STEP_combo, S_6),
[comb_N_MEN] = COMBO(N_MEN_combo, G_COMM),
[comb_N_BOL] = COMBO(N_BOL_combo, G_DOT),
[comb_N_KAV] = COMBO(N_KAV_combo, S_QUOT),
[comb_N_AND] = COMBO(N_AND_combo, S_7),  
};

// действия для комбо
void process_combo_event(uint16_t combo_index, bool pressed) { 
  switch(combo_index) {
    case comb_ZAP: // запятая
      if (pressed) {
        tap_code(KC_COMM);
        tap_code(KC_SPC);        
      }
      break;
    case comb_TOCH: // точка
      if (pressed) {
        tap_code(KC_DOT);
        tap_code(KC_SPC);
        set_oneshot_mods (MOD_LSFT);
      }
      break;
    case comb_ZSCOB: // закрытая скобка
      if (pressed) {
        tap_code16(S(KC_0));
        tap_code(KC_SPC);
      }
      break;
    case comb_ZKAV: // закрытая кавычка » 0187
      if (pressed) {
        register_code(KC_LALT);
        tap_code(KC_P0);
        tap_code(KC_P1);
        tap_code(KC_P8);
  tap_code(KC_P7);
        unregister_code(KC_LALT);
  tap_code(KC_SPC);      
      }
      break;      
    case comb_TZ: // точка c запятой
      if (pressed) {
        tap_code(KC_SCLN);
        tap_code(KC_SPC);
      }
      break;
    case comb_DT: // двоеточие
      if (pressed) {
        tap_code16(S(KC_SCLN));
        tap_code(KC_SPC);
      }
      break;
    case comb_TIRE: // тире
      if (pressed) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        register_code(KC_LSFT);
        register_code(KC_5);
        unregister_code(KC_5);
        unregister_code(KC_LSFT);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      break;
    case comb_VOS: // !
      if (pressed) {
        tap_code16(S(KC_1));
        tap_code(KC_SPC);
        set_oneshot_mods (MOD_LSFT);
      }
      break;
     case comb_VOP: // ?
      if (pressed) {
        tap_code16(S(KC_SLSH));
        tap_code(KC_SPC);
        set_oneshot_mods (MOD_LSFT);
      }
      break;
    case comb_PER1: // alt shift таб
      if (pressed) {
        register_code(KC_LALT);
        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
        unregister_code(KC_LALT);
      }
      break;
    case comb_OCH: // очистить строку
      if (pressed) {
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        unregister_code(KC_LSFT);
        tap_code(KC_DEL);
      }
      break;    
    case comb_UPR1: // залипший упр (левый)
      if (pressed) {
        set_oneshot_mods (MOD_LCTL);
      }
      break;        
    case comb_DOP: // залипший ДОП (левый)
      if (pressed) {
        set_oneshot_mods (MOD_LALT);
      }
      break;        
    case comb_REG1: // залипший Рег (левый)
      if (pressed) {
        set_oneshot_mods (MOD_LSFT);
      }
      break;       
    case comb_REG2: // пробел и залипший Рег (правый)
      if (pressed) {
        tap_code(KC_SPC);
        set_oneshot_mods (MOD_LSFT);
      }
      break;
    case comb_SOYI: // ctr PGDN
      if (pressed) {
        tap_code(KC_SPC);
        tap_code(KC_I);
        tap_code(KC_SPC);
      }
      break;
    case comb_BUKTZ: // ctr PGDN
      if (pressed) {
        register_code(KC_LALT);
        tap_code(KC_P2);
        tap_code(KC_P3);
        tap_code(KC_P4);
        unregister_code(KC_LALT);
      }
      break;
  }
}

typedef struct { //назначение структуры нажатий https://docs.qmk.fm/#/feature_tap_dance?id=how-to-use
    bool is_press_action;
    uint8_t state;
} tap;

uint8_t cur_dance(qk_tap_dance_state_t *state) { // определение состояния двойного нажатия
    if (state->count == 1) { //если нажата один раз
        if (!state->pressed) return SINGLE_TAP; // если не удерживается, то Одиночное нажатие
        else return SINGLE_HOLD; // иначе Одиночное удержание
    } else if (state->count == 2) return DOUBLE_TAP; // если нажата два раза, то Двойное нажатие
    else return 8; // магическое число (на будущее)
}
static tap ql_tap_state = { // Инициализация двойного нажатия
    .is_press_action = true,
    .state = 0 // обнуление состояния
};
 
void x_finished(qk_tap_dance_state_t *state, void *user_data) { // функция реакции двойного нажатия Р/А. Действие при нажатии
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code(KC_CAPS); break; // нажатие КАПС
        case SINGLE_HOLD: register_code(KC_CAPS); break; // нажатие КАПС
    }
}
void x_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании (то отключить слой)
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_CAPS); break; // снятие КАПС
        case SINGLE_HOLD: register_code(KC_CAPS); break; // нажатие КАПС
    }
    ql_tap_state.state = 0; // обнуление состояния
};

qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [VYH] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)), // выход или альт+ф4
    [TABB] = ACTION_TAP_DANCE_DOUBLE(A(KC_TAB), C(A(KC_TAB))), // таб или альт+таб https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
    [WEMO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_DOT)), // вин или эмодзи
    [POISK] = ACTION_TAP_DANCE_DOUBLE(KC_F3, C_F), // поиск
    [RU_AN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset), // Р/А
};

//Создание кнопок
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions#programming-the-behavior-of-any-keycode-id-programming-the-behavior-of-any-keycode
  switch (keycode) {    
    case PS_1: COD("pas")
    case G_COMM: COD(SS_LALT(SS_TAP(X_KP_6)SS_TAP(X_KP_0)) // <
    case G_DOT: COD(SS_LALT(SS_TAP(X_KP_6)SS_TAP(X_KP_2)) // >
    case G_SP: COD(SS_LALT(SS_TAP(X_KP_6)SS_TAP(X_KP_2)) // неразрывный пробел
    case KC_LSFT: // записать, что РЕГ нажат
        shift_held = record->event.pressed;
    return true;
    break;
    case KCCYO: REG_R(KC_E, 0, KC_E, 1) // Ё
    case ZAP:  REG_R(KC_COMM, 0, KC_5, 1) // , %
    case VOPR:  REG_R(KC_SLSH, 1, KC_1, 1) // ? !
    case KAVYCH:  REG_R(KC_QUOT, 1, KC_QUOT, 0) // Кавычки
    case ZVEZD: REG_R(KC_PAST, 0, KC_2, 1) // * @
    case SLESH:  REG_R(KC_PSLS, 0, KC_BSLS, 0) // слеши обратного нет!
    case OSKOB:  REG_R(KC_9, 1, KC_5, 1) // открытая скобка
    case ZSKOB:  REG_R(KC_0, 1, KC_5, 1) // закрытая скобка      
    case PLUS:  REG_R(KC_EQL, 1, KC_EQL, 0) // + =      
    case TOCH:  REG_R(KC_DOT, 0, KC_4, 1)        
    case OTMENA: REG_R(C_Z, 0, C_Y, 0)
    case SOHR: REG_R(C_S, 0, KC_F12, 0)
    case KOP1: REG_R(C_INS, 0, C_X, 0)
    case VST1: REG_R(KC_INS, 1, KC_INS, 0)
    case RU_E: 
    case RU_TY: 
    case KK_LBRC:
    case KK_RBRC: 
    case UDAR: 
      if (!record->event.pressed) {
      uint16_t index = keycode - SWE_AA;
      uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT));
      unregister_code(KC_LSFT);
      send_string(alt_codes[index][(bool)shift]);
      if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
      return false;
    }
    default:
        return true;
  }
  return true;
}
