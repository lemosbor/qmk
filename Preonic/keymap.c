#include QMK_KEYBOARD_H //  qmk compile -kb xd75 -km leo

#define L_OSNOVA 0 // слой 0 (основной)
#define L_DOP 1 // слой 1 (сервисный)

// функция подмены вернего регистра
#define REG_R2(kn1, kn2) \
if (record->event.pressed) { \
  if (shift_held) { \
        unregister_code(KC_LSFT); \
        kn2; \
        register_code(KC_LSFT); \
  } else { \
        kn1; \
    } \
} \
//return false;  !!!

// функция отправки текста
#define COD(code) \
if (record->event.pressed) { \
        SEND_STRING(code); \
      } \
      break; \
//return false;  !!!

// сочетания клавиш в одну команду
#define C_INS C(KC_INS)
#define S_INS S(KC_INS)
#define C_PGUP C(KC_PGUP)
#define C_PGDN C(KC_PGDN)
#define C_ENT C(KC_ENT)
#define C_X C(KC_X)
#define C_S C(KC_S)
#define C_Z C(KC_Z)
#define C_Y C(KC_Y)
#define C_F C(KC_F)
#define S_SCLN S(KC_SCLN)
#define S_4 S(KC_4)
#define S_6 S(KC_6)
#define S_7 S(KC_7)
#define S_9 S(KC_9)
#define S_0 S(KC_0)
#define S_QUOT S(KC_QUOT)
#define S_COMM S(KC_COMM)
#define S_DOT S(KC_DOT)
#define ALSTB A(S(KC_TAB))
#define ALTB A(KC_TAB)

bool shift_held = false; // обнуляем индикатор зажатого РЕГ

//клавиши с двойными нажатиями
enum {
    SINGLE_TAP = 1, // одиночное нажатие
    SINGLE_HOLD, // одиночное удержание
    DOUBLE_TAP, // двойное нажатие
    VYH, // Вых / альт+Ф4
    TABB, // переход между окнами
    POISK, // поиск
    RU_AN, // кнопка Р/А
    SOHR, // сохранить
    KOP1, // копировать
    VST1, // вставить
    VYDEL, // выделить
};
// клавиши с одной командой
enum custom_keycodes { 
  VOPR = SAFE_RANGE, // ?
  SLESH, // /
  KAVYCH, // "
  OSKOB, // (
  ZSKOB, // )
  OTMENA, // отмена/повтор
  PS_1, // текст 1
  PS_2, // текст 2
  PS_3, // текст 3
  PS_4, // текст 4
  PS_5, // текст 5
  RU_E, // ё
  RU_TY, // ъ
  KK_LBRC, // [
  KK_RBRC, // ]
  UDAR, // `
  G_SP, // неразрывный пробел
  RU_TIR, // —
  UD_STROK, // удалить строку
  VSTVVOD, // вставить и нажать ввод
  STEPE, // степень
  GRADU, // градус
  UMNO, // умножение
}; 

enum combo_events { // обозначение комбо-команд
comb_TOCH, comb_ZAP, comb_TZ, comb_DT, comb_DEF, comb_TIRE, comb_VOS, comb_VOP, comb_DOP, comb_REG1, comb_REG2, comb_PROB, comb_NACH, comb_KON, comb_LEV, comb_PRAV, comb_VERH,
comb_VNIZ, comb_VSH, comb_VVOD, comb_UDL, comb_TAB, comb_VIH, comb_KOP1, comb_VST1, comb_UPR1, comb_OTM, comb_N1, comb_N2, comb_N3, comb_N4, comb_N5, comb_N6, comb_N7, comb_N8,
comb_N9, comb_N0, comb_ALTB, comb_INS, comb_VYR, comb_PER1, comb_PER2, comb_OCH, comb_VVOD2, comb_PER3, comb_SOYI, comb_BUKTZ, comb_ZSCOB, comb_OSCOB, comb_OKAV, comb_ZKAV,  
comb_KAV, comb_PROB2, comb_PGUP, comb_PGDN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // определение матриц
/* 
ц ь у ч ш ъ х п л м й
и а е о с щ к н т в р
э ё ы я ю ф г д б ж з
 */
[L_OSNOVA] = LAYOUT_preonic_grid( \
  TD(KOP1),      TD(VST1),      KC_COMM,     VOPR,      KAVYCH,   KC_SCLN, KC_EQL,  SLESH,   KC_DOT,    KC_MINS,  OSKOB,    ZSKOB, \
  KC_C,          KC_X,          KC_U,        KC_GRV,    KC_LBRC,  KC_BSPC, KC_F,    KC_H,    KC_P,      KC_L,     KC_M,     KC_J, \
  KC_I,          KC_A,          KC_E,        KC_O,      KC_S,     KC_ENT,  KC_RBRC, KC_K,    KC_N,      KC_T,     KC_W,     KC_R, \
  SFT_T(KC_BSLS),RU_E,          KC_Q,        KC_Y,      KC_NUBS,  KC_DEL,  KC_UP,   KC_G,    KC_D,      KC_B,     KC_V,     KC_Z, \
  CTL_T(KC_ESC), LGUI_T(KC_TAB),ALT_T(KC_F2),TD(POISK), KC_SPC,   KC_LEFT, KC_DOWN, KC_RGHT, OSL(L_DOP),TD(RU_AN),OTMENA,   TD(TABB) \
),
[L_DOP] = LAYOUT_preonic_grid( \                       
  RGB_TOG,      RGB_MOD,        KC_TRNS,     STEPE,     UDAR,     KC_PAST, KC_F10,  KC_F11,  KC_F12,    RU_TIR,   KK_LBRC,  KK_RBRC, \
  KC_NUMLOCK,   RU_TY,          KC_TRNS,     KC_TRNS,   KC_PSCR,  KC_TRNS, KC_F7,   KC_F8,   KC_F9,     KC_7,     KC_8,     KC_9, \
  KC_MUTE,      KC_VOLD,        KC_VOLU,     KC_MSTP,   KC_MNXT,  KC_TRNS, KC_F4,   KC_F5,   KC_F6,     KC_4,     KC_5,     KC_6, \
  KC_TRNS,      KC_BRID,        KC_BRIU,     C(S(KC_ESC)),KC_TRNS,KC_TRNS, KC_F1,   KC_F2,   KC_F3,     KC_1,     KC_2,     KC_3, \
  A(KC_F4),     KC_TRNS,        KC_TRNS,     KC_TRNS,   G_SP,     KC_HOME, KC_PGDN, KC_END,  KC_TRNS,   KC_TRNS,  KC_0,     KC_TRNS \
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

// задаем сочитание клавиш (комбо)
const uint16_t PROGMEM TOCH_combo[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM ZAP_combo[] = {KC_U, KC_GRV, COMBO_END};
const uint16_t PROGMEM TZ_combo[] = {KC_GRV, KC_LBRC, COMBO_END};
const uint16_t PROGMEM DT_combo[] = {KC_H, KC_P, COMBO_END};
const uint16_t PROGMEM DEF_combo[] = {KC_O, KC_N, COMBO_END};
const uint16_t PROGMEM TIRE_combo[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM VOS_combo[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM VOP_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM REG1_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM REG2_combo[] = {KC_GRV, KC_S, COMBO_END};
const uint16_t PROGMEM PROB_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM PROB2_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM NACH_combo[] = {KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM KON_combo[] = {KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM LEV_combo[] = {KC_W, KC_T, COMBO_END};
const uint16_t PROGMEM PRAV_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM VERH_combo[] = {KC_L, KC_M, COMBO_END};
const uint16_t PROGMEM VNIZ_combo[] = {KC_B, KC_V, COMBO_END};
const uint16_t PROGMEM VSH_combo[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM VVOD_combo[] = {KC_O, KC_S, COMBO_END};
const uint16_t PROGMEM UDL_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM TAB_combo[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM VIH_combo[] = {KC_M, KC_J, COMBO_END};
const uint16_t PROGMEM KOP1_combo[] = {KC_X, KC_U, COMBO_END};
const uint16_t PROGMEM VST1_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM VYR_combo[] = {KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM UPR1_combo[] = {KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM OTM_combo[] = {KC_GRV, KC_O, COMBO_END};
const uint16_t PROGMEM N1_combo[] = {KC_RGHT, KC_N, COMBO_END};
const uint16_t PROGMEM N2_combo[] = {KC_RGHT, KC_T, COMBO_END};
const uint16_t PROGMEM N3_combo[] = {KC_RGHT, KC_W, COMBO_END};
const uint16_t PROGMEM N4_combo[] = {KC_RGHT, KC_R, COMBO_END};
const uint16_t PROGMEM N5_combo[] = {KC_RGHT, KC_H, COMBO_END};
const uint16_t PROGMEM N6_combo[] = {KC_RGHT, KC_P, COMBO_END};
const uint16_t PROGMEM N7_combo[] = {KC_RGHT, KC_L, COMBO_END};
const uint16_t PROGMEM N8_combo[] = {KC_RGHT, KC_M, COMBO_END};
const uint16_t PROGMEM N9_combo[] = {KC_RGHT, KC_J, COMBO_END};
const uint16_t PROGMEM N0_combo[] = {KC_RGHT, KC_K, COMBO_END};
const uint16_t PROGMEM ALTB_combo[] = {KC_N, KC_B, COMBO_END};
const uint16_t PROGMEM INS_combo[] = {KC_C, KC_I, COMBO_END};
const uint16_t PROGMEM PER1_combo[] = {KC_W, KC_B, COMBO_END};
const uint16_t PROGMEM PER2_combo[] = {KC_W, KC_L, COMBO_END};
const uint16_t PROGMEM OCH_combo[] = {KC_Q, KC_Y, COMBO_END};
const uint16_t PROGMEM VVOD2_combo[] = {KC_K, KC_N, COMBO_END};
const uint16_t PROGMEM PER3_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM SOYI_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM BUKTZ_combo[] = {KC_I, KC_X, COMBO_END};
const uint16_t PROGMEM DOP_combo[] = {KC_D, KC_T, COMBO_END};
const uint16_t PROGMEM ZSCOB_combo[] = {KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM OSCOB_combo[] = {KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM OKAV_combo[] = {KC_C, KC_P, COMBO_END};
const uint16_t PROGMEM ZKAV_combo[] = {KC_GRV, KC_J, COMBO_END};
const uint16_t PROGMEM KAV_combo[] = {KC_S, KC_K, COMBO_END};
const uint16_t PROGMEM PGUP_combo[] = {KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM PGDN_combo[] = {KC_W, KC_V, COMBO_END};
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
[comb_PROB2] = COMBO(PROB2_combo, KC_SPC),
[comb_NACH] = COMBO(NACH_combo, KC_HOME),
[comb_KON] = COMBO(KON_combo, KC_END),
[comb_LEV] = COMBO(LEV_combo, KC_LEFT),
[comb_PRAV] = COMBO(PRAV_combo, KC_RGHT),
[comb_VERH] = COMBO(VERH_combo, KC_UP),
[comb_VNIZ] = COMBO(VNIZ_combo, KC_DOWN),
[comb_VSH] = COMBO(VSH_combo, KC_BSPC),
[comb_ALTB] = COMBO(ALTB_combo, ALTB),
[comb_VVOD] = COMBO(VVOD_combo, KC_ENT),
[comb_VVOD2] = COMBO(VVOD2_combo, C_ENT),
[comb_UDL] = COMBO(UDL_combo, KC_DEL),
[comb_TAB] = COMBO(TAB_combo, KC_TAB),
[comb_VIH] = COMBO(VIH_combo, KC_ESC),
[comb_KOP1] = COMBO(KOP1_combo, C_INS),
[comb_VST1] = COMBO(VST1_combo, S_INS),
[comb_VYR] = COMBO(VYR_combo, C_X),
[comb_UPR1] = COMBO_ACTION(UPR1_combo),
[comb_OTM] = COMBO(OTM_combo, C_Z),
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
[comb_PER1] = COMBO(PER1_combo, ALSTB),
[comb_PER2] = COMBO(PER2_combo, C_PGDN),
[comb_PER3] = COMBO(PER3_combo, C_PGUP),
[comb_OCH] = COMBO_ACTION(OCH_combo),
[comb_SOYI] = COMBO_ACTION(SOYI_combo),
[comb_BUKTZ] = COMBO_ACTION(BUKTZ_combo),
[comb_DOP] = COMBO_ACTION(DOP_combo),
[comb_OSCOB] = COMBO_ACTION(OSCOB_combo),
[comb_ZSCOB] = COMBO(ZSCOB_combo, S_0),
[comb_OKAV] = COMBO_ACTION(OKAV_combo),
[comb_ZKAV] = COMBO_ACTION(ZKAV_combo),
[comb_KAV] = COMBO(KAV_combo, S_QUOT),
[comb_PGUP] = COMBO(PGUP_combo, KC_PGUP),
[comb_PGDN] = COMBO(PGDN_combo, KC_PGDN),
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
        set_oneshot_mods (MOD_LSFT); // clear_oneshot_mods();
      }
      break;      
    case comb_OSCOB: // открытая скобка
      if (pressed) {
        tap_code(KC_SPC);
        tap_code16(S(KC_9));        
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
      }
      break;      
    case comb_OKAV: // открытая кавычка
      if (pressed) {
        tap_code(KC_SPC);   
        register_code(KC_LALT);
        tap_code(KC_P0);
        tap_code(KC_P1);
        tap_code(KC_P7);
        tap_code(KC_P1);
        unregister_code(KC_LALT);
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
       tap_code(KC_SPC);
        register_code(KC_LALT);
        tap_code(KC_P0);
        tap_code(KC_P1);
        tap_code(KC_P5);
        tap_code(KC_P1);
        unregister_code(KC_LALT);
        tap_code(KC_SPC);
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
    case comb_SOYI: // _и_
      if (pressed) {
        tap_code(KC_SPC);
        tap_code(KC_I);
        tap_code(KC_SPC);
      }
      break;
    case comb_BUKTZ: // ъ
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
void soh_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code16(C(KC_S)); break;
        case DOUBLE_TAP: register_code16(C(KC_S)); break;
    }
}
void soh_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code16(C(KC_S)); tap_code16(A(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(C(KC_S)); tap_code16(A(KC_F4)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void vydel_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: tap_code16(C(KC_LEFT)); register_code(KC_LSFT);  break;
        case DOUBLE_TAP: tap_code(KC_HOME); register_code(KC_LSFT);  break;
        case SINGLE_HOLD: register_code16(C(KC_A)); break;
    }
}
void vydel_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: tap_code16(C(KC_RGHT)); unregister_code(KC_LSFT); break;
        case DOUBLE_TAP: tap_code(KC_END); unregister_code(KC_LSFT); break;
        case SINGLE_HOLD: unregister_code16(C(KC_A)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [VYH] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)),// выйти / принудительно закрыть [WEMO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_DOT)), // вин или эмодзи
    [POISK] = ACTION_TAP_DANCE_DOUBLE(KC_F3, C_F), // поиск
    [RU_AN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset), // Р/А
    [SOHR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, soh_finished, soh_reset), // сохранить
    [VYDEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vydel_finished, vydel_reset), // выделить
    [TABB] = ACTION_TAP_DANCE_DOUBLE(ALTB, ALSTB), // переход между окнами
    [KOP1] = ACTION_TAP_DANCE_DOUBLE(C(KC_INS), C(KC_X)), // копировать
    [VST1] = ACTION_TAP_DANCE_DOUBLE(S(KC_INS), VSTVVOD), // вставить
};

//Создание кнопок
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions#programming-the-behavior-of-any-keycode-id-programming-the-behavior-of-any-keycode
  switch (keycode) {    
    case PS_1: COD("ц"SS_TAP(X_ENT))
    case PS_2: COD("ц"SS_TAP(X_ENT))
    case PS_3: COD("ц"SS_TAP(X_ENT))
    case PS_4: COD("ц"SS_TAP(X_ENT))
    case PS_5: COD("ц"SS_TAP(X_ENT))
    case G_SP:  COD(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_5))) // неразрывный пробел
    case KC_LSFT: // записать, что РЕГ нажат
        shift_held = record->event.pressed;
    return true;
    break;
    case SFT_T(KC_BSLS): // записать, что РЕГ нажат
        shift_held = record->event.pressed;
    return true;
    break;          
    case UD_STROK:
      if (record->event.pressed) {        
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        unregister_code(KC_LSFT);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
      }
      break;          
    case VSTVVOD:
      if (record->event.pressed) {        
        tap_code16(S(KC_INS));
        tap_code(KC_ENT);
      }
      break;
    //case KC_9: 
     //if (record->event.pressed) {
      // if (shift_held) { 
       //SEND_STRING(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2))); send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_8))),
      // } //else { 
   // }
   // }
  // return true;
  //   break;
    case VOPR:  REG_R2(tap_code16(S(KC_SLSH)), send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_2))))
    case KAVYCH: REG_R2(tap_code16(S(KC_QUOT)), tap_code(KC_QUOT))
    case ZSKOB:  REG_R2(tap_code16(S(KC_0)), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_7))))  
    case OTMENA: REG_R2(tap_code16(C(KC_Z)), tap_code16(C(KC_Y)))
    case SLESH: REG_R2(tap_code(KC_PSLS), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_4))))
    case OSKOB: REG_R2(tap_code16(S(KC_9)), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_1))))
    case RU_E: REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_1))), send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_0))))
    case RU_TY: REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_4))), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_4))))
    case KK_LBRC:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_1))), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_3))))
    case KK_RBRC: REG_R2(send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_3))), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_5))))
    case UDAR: REG_R2(send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_6))), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_7)SS_TAP(X_KP_6)SS_TAP(X_KP_9))))
    case RU_TIR:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_1))), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_6))))
    case STEPE:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2))), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_9))))
    case GRADU:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_8))), send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_6))))
    case UMNO:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_5))), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_7))))
   }
  return true;
}
