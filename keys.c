#define L_OSNOVA 0 // слой 0 (основной)
#define L_DOP 1 // слой 1 (сервисный)

// функция подмены верхнего регистра
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
return false;

// функция отправки текста
#define COD(code) \
if (record->event.pressed) { \
        SEND_STRING(code); \
      } \
      break; \
return false;

// сочетания клавиш в одну команду
#define C_INS C(KC_INS)
#define S_INS S(KC_INS)
#define C_PGUP C(KC_PGUP)
#define C_PGDN C(KC_PGDN)
#define C_ENT C(KC_ENT)
#define C_A C(KC_A)
#define C_D C(KC_D)
#define C_E C(KC_E)
#define C_G C(KC_G)
#define C_K C(KC_K)
#define C_C C(KC_C)
#define C_V C(KC_V)
#define C_L C(KC_L)
#define C_N C(KC_N)
#define C_X C(KC_X)
#define C_O C(KC_O)
#define C_Q C(KC_Q)
#define C_S C(KC_S)
#define C_H C(KC_H)
#define C_B C(KC_B)
#define C_SP C(KC_SPC)
#define A_EQ A(KC_EQL)
#define C_P C(KC_P)
#define C_T C(KC_T)
#define C_Z C(KC_Z)
#define C_Y C(KC_Y)
#define C_F C(KC_F)
#define C_UP C(KC_UP)
#define C_DW C(KC_DOWN)
#define C_HOME C(KC_HOME)
#define S_SCLN S(KC_SCLN)
#define S_SP S(KC_SPC)
#define S_2 S(KC_2)
#define S_3 S(KC_3)
#define S_4 S(KC_4)
#define S_5 S(KC_5)
#define S_6 S(KC_6)
#define S_7 S(KC_7)
#define S_9 S(KC_9)
#define S_0 S(KC_0)
#define S_MI S(KC_MINS)
#define S_QUOT S(KC_QUOT)
#define S_COMM S(KC_COMM)
#define S_DOT S(KC_DOT)
#define ALSTB A(S(KC_TAB))
#define A_T A(KC_T)
#define C_S_ES C(S(KC_ESC))
#define CS_L C(S(KC_L))
#define ALES A(KC_ESC)
#define DUB C(S(KC_D))
#define C_A_DL C(A(KC_DEL))
#define STAB S(KC_TAB)
#define CBS C(KC_BSPC)
#define GIP_L G(KC_L)
#define GIPS_S SGUI(KC_S)


#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI
//индикаторы
bool shift_held = false; // обнуляем индикатор зажатого РЕГ
bool gpu_active = false;
/*bool twz_active = false;
uint16_t twz_timer = 0;   */
bool shift_active = false;
uint16_t shift_timer = 0; 
bool skob_active = false;
bool kav_active=false;
bool caps_active=false;
bool u_active = false;
bool y_active = false;

bool comotE_active = false;
uint16_t comotE_timer = 0;  
bool comotS_active = false;
uint16_t comotS_timer = 0; 

//клавиши с двойными нажатиями
enum {
    SINGLE_TAP = 1, // одиночное нажатие
    SINGLE_HOLD, // одиночное удержание
    DOUBLE_TAP, // двойное нажатие
    VYH, // Вых / альт+Ф4
    POISK, // поиск
    RU_AN, // кнопка Р/А
    SOHR, // сохранить
    KOP1, // копировать
    VST1, // вставить
    VYDEL, // выделить
    OSKOBT, // открытая скобка
    ZSKOBT, // закрытая скобка
    MINS,   // минус
    GIP,
    SCLN,
    VOPRR,
};
// клавиши с одной командой
enum custom_keycodes { 
  VOPR = SAFE_RANGE, // ?
  ZAP,
  TOCH,
  SLESH, // /
  KAVYCH, // "
  OTMENA, // отмена/повтор 
  PS_1, // текст 1
  PS_2, // текст 2
  PS_3, // текст 3
  PS_4, // текст 4
  PS_5, // текст 5
  RU_TY, // ъ
  UDAR, // `
  G_SP, // неразрывный пробел
  G_NOM,
  G_PARA,
  MINMIN, // —
  UD_STROK, // удалить строку
  STEPE, // степень
  GRADU, // градус
  UMNO, // умножение
  KC_RESET, // перезагрузка клавиатуры
}; 

enum combo_events { // обозначение комбо-команд
comb_TOCH, comb_ZAP, comb_TZ, comb_DT, comb_DEF, comb_TIRE, comb_VOS, comb_VOP, comb_CD, comb_REG1, comb_REG2, comb_PROB, comb_NACH, comb_KON, comb_LEV, comb_PRAV, comb_VERH,
comb_VNIZ, comb_VSH, comb_STR, comb_VIH, comb_CN, comb_STAB, comb_UDST, 
comb_SAB, comb_AND, comb_DOL, comb_PR, comb_SHY,
comb_C, comb_H, comb_CVSH, comb_INS, comb_CO, comb_UDVS, comb_VVOD2, comb_PER3,comb_PER2, comb_CADEL, comb_OSCOB, comb_OKAV,  
comb_KAV, comb_PROB2, comb_CT, comb_GIPL, comb_SOH, comb_CK,  comb_CP, comb_CA, comb_RESH,  comb_GSS, comb_PER, comb_CDW, 
comb_CSES, comb_F4, comb_F5, comb_F11, comb_BR, comb_CUP, comb_CE, comb_PLUS, comb_RAV,
comb_N_BOL, comb_AEQ, comb_N_KAV, comb_N_AND, comb_N_ZAP, comb_N_TOCH, comb_N_DEL, comb_N_UMN, comb_N_MIN, comb_N_PLUS, comb_N_RAV, comb_N_DT, comb_N_TZ, comb_N_DOL, comb_N_STEP, comb_N_MEN,
comb_SOYI, comb_PROCH, comb_VST, 34_combo, 12_combo, 13_combo, 14_combo, 15_combo, 16_combo, 20_combo, MON2_combo,
};

// задаем сочетания комбо-клавиш
const uint16_t PROGMEM TOCH_combo[] = {KC_Z , KC_L, COMBO_END};
const uint16_t PROGMEM ZAP_combo[] = {KC_I, KC_Y, COMBO_END};
const uint16_t PROGMEM TZ_combo[] = {KC_Y,  KC_F15, COMBO_END};
const uint16_t PROGMEM DT_combo[] = {KC_J,  KC_Z, COMBO_END};
const uint16_t PROGMEM DEF_combo[] = {KC_O, KC_T, COMBO_END};
const uint16_t PROGMEM TIRE_combo[] = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM VOS_combo[] = {KC_X, KC_U, COMBO_END};
const uint16_t PROGMEM VOP_combo[] = {KC_LBRC, KC_NUBS, COMBO_END};
const uint16_t PROGMEM REG1_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM REG2_combo[] = {KC_Y, KC_Q, COMBO_END};
const uint16_t PROGMEM VVOD2_combo[] = {KC_O, KC_Q, COMBO_END};
const uint16_t PROGMEM PROB_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM PROB2_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM NACH_combo[] = {KC_LEFT, KC_M, COMBO_END};
const uint16_t PROGMEM KON_combo[] = {KC_RGHT, KC_B, COMBO_END};
const uint16_t PROGMEM LEV_combo[] = {KC_N, KC_K, COMBO_END};
const uint16_t PROGMEM PRAV_combo[] = {KC_K, KC_W, COMBO_END};
const uint16_t PROGMEM VERH_combo[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM VNIZ_combo[] = {KC_R, KC_M, COMBO_END};
const uint16_t PROGMEM VSH_combo[] = {KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM STR_combo[] = {KC_BSLS, KC_I, COMBO_END};
const uint16_t PROGMEM VIH_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM CN_combo[] = {KC_N, KC_D, COMBO_END};
const uint16_t PROGMEM CO_combo[] = {KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM STAB_combo[] = {KC_Q, KC_TAB, COMBO_END};
const uint16_t PROGMEM UDST_combo[] = {KC_TAB, KC_DEL, COMBO_END};
const uint16_t PROGMEM SAB_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM AND_combo[] = {KC_H, KC_G , COMBO_END};
const uint16_t PROGMEM DOL_combo[] = {KC_J, KC_V, COMBO_END};
const uint16_t PROGMEM PR_combo[] = {KC_P, KC_R, COMBO_END};
const uint16_t PROGMEM SHY_combo[] = {KC_Z, KC_N, COMBO_END};
const uint16_t PROGMEM C_combo[] = {KC_V, KC_N, COMBO_END};
const uint16_t PROGMEM H_combo[] = {KC_N, KC_P, COMBO_END};
const uint16_t PROGMEM CVSH_combo[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM INS_combo[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM UDVS_combo[] = {KC_DEL, KC_ENT, COMBO_END};
const uint16_t PROGMEM PER3_combo[] = {KC_M, KC_B, COMBO_END};
const uint16_t PROGMEM PER2_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM CE_combo[] = {KC_E, KC_BSLS, COMBO_END};
const uint16_t PROGMEM CADEL_combo[] = {KC_C, KC_J, COMBO_END};
const uint16_t PROGMEM CD_combo[] = {KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM OSCOB_combo[] = {KC_NUBS, KC_X, COMBO_END};
const uint16_t PROGMEM OKAV_combo[] = {KC_LBRC, KC_U, COMBO_END};
const uint16_t PROGMEM KAV_combo[] = {KC_Q, KC_V, COMBO_END};
const uint16_t PROGMEM CT_combo[] = {KC_G, KC_T, COMBO_END};
const uint16_t PROGMEM GIPL_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM SOH_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM CK_combo[] = {KC_K, KC_R, COMBO_END};
const uint16_t PROGMEM CP_combo[] = {KC_K, KC_P, COMBO_END};
const uint16_t PROGMEM CA_combo[] = {KC_S, KC_LBRC, COMBO_END};
const uint16_t PROGMEM RESH_combo[] = {KC_R, KC_LBRC, COMBO_END};
const uint16_t PROGMEM GSS_combo[] = {KC_S, KC_NUBS, COMBO_END};
const uint16_t PROGMEM PER_combo[] = {KC_W, KC_B, COMBO_END};
const uint16_t PROGMEM CDW_combo[] = {KC_R, KC_DOWN, COMBO_END};
const uint16_t PROGMEM CSES_combo[] = {KC_RBRC, KC_C, COMBO_END};
const uint16_t PROGMEM F4_combo[] = {KC_E, KC_NUBS, COMBO_END};
const uint16_t PROGMEM F5_combo[] = {KC_DOWN, KC_LEFT, COMBO_END};
const uint16_t PROGMEM F11_combo[] = {KC_LEFT, KC_RGHT, COMBO_END};
const uint16_t PROGMEM BR_combo[] = {KC_UP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM CUP_combo[] = {KC_P, KC_UP, COMBO_END};
const uint16_t PROGMEM PLUS_combo[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM RAV_combo[] = {KC_R, KC_W, COMBO_END};

const uint16_t PROGMEM N_ZAP_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM AEQ_combo[] = {KC_EQL, KC_7, COMBO_END};
const uint16_t PROGMEM N_TOCH_combo[] = {KC_5, KC_3, COMBO_END};
const uint16_t PROGMEM N_DEL_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM N_UMN_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM N_MIN_combo[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM N_PLUS_combo[] = {KC_6, KC_5, COMBO_END};
const uint16_t PROGMEM N_RAV_combo[] = {KC_4, KC_6, COMBO_END};
const uint16_t PROGMEM N_DT_combo[] = {KC_4, KC_8, COMBO_END};
const uint16_t PROGMEM N_TZ_combo[] = {KC_8, KC_6, COMBO_END};
const uint16_t PROGMEM N_DOL_combo[] = {KC_4, KC_2, COMBO_END};
const uint16_t PROGMEM N_STEP_combo[] = {KC_1, KC_8, COMBO_END};
const uint16_t PROGMEM N_MEN_combo[] = {KC_1, KC_0, COMBO_END};
const uint16_t PROGMEM N_BOL_combo[] = {KC_0, KC_3, COMBO_END};
const uint16_t PROGMEM N_KAV_combo[] = {KC_7, KC_9, COMBO_END};
const uint16_t PROGMEM N_AND_combo[] = {KC_2, KC_6, COMBO_END};
const uint16_t PROGMEM SOYI_combo[] = {KC_I, KC_SPC, COMBO_END};
const uint16_t PROGMEM PROCH_combo[] = {KC_G, KC_SPC, COMBO_END};
const uint16_t PROGMEM VST_combo[] = {KC_BSLS, KC_A, COMBO_END};
const uint16_t PROGMEM 34_combo[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM 12_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM 13_combo[] = {KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM 14_combo[] = {KC_1, KC_4, COMBO_END};
const uint16_t PROGMEM 15_combo[] = {KC_1, KC_5, COMBO_END};
const uint16_t PROGMEM 16_combo[] = {KC_1, KC_6, COMBO_END};
const uint16_t PROGMEM 20_combo[] = {KC_2, KC_0, COMBO_END};
const uint16_t PROGMEM MON2_combo[] = {KC_RGHT, KC_R, COMBO_END};

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
[comb_PROB2] = COMBO_ACTION(PROB2_combo),
[comb_NACH] = COMBO(NACH_combo, KC_HOME),
[comb_KON] = COMBO(KON_combo, KC_END),
[comb_LEV] = COMBO(LEV_combo, KC_LEFT),
[comb_PRAV] = COMBO(PRAV_combo, KC_RGHT),
[comb_VERH] = COMBO(VERH_combo, KC_UP),
[comb_VNIZ] = COMBO(VNIZ_combo, KC_DOWN),
[comb_VSH] = COMBO(VSH_combo, KC_BSPC),
[comb_CVSH] = COMBO(CVSH_combo, CBS),
[comb_VVOD2] = COMBO(VVOD2_combo, C_ENT),
[comb_STR] = COMBO(STR_combo, S_SP),
[comb_VIH] = COMBO(VIH_combo, C_SP),
[comb_CN] = COMBO(CN_combo, C_N),
[comb_CO] = COMBO(CO_combo, C_O),
[comb_STAB] = COMBO(STAB_combo, STAB),
[comb_UDST] = COMBO_ACTION(UDST_combo),
[comb_SAB] = COMBO(SAB_combo, S_2),
[comb_AND] = COMBO(AND_combo, S_7),
[comb_DOL] = COMBO(DOL_combo, S_4),
[comb_PR] = COMBO(PR_combo, S_5),
[comb_C] = COMBO(C_combo, KC_C),
[comb_H] = COMBO(H_combo, KC_H),
[comb_INS] = COMBO(INS_combo, KC_INS),
[comb_UDVS] = COMBO_ACTION(UDVS_combo),
[comb_PER3] = COMBO(PER3_combo, ALES),
[comb_CADEL] = COMBO(CADEL_combo, C_A_DL),
[comb_CD] = COMBO(CD_combo, C_D),
[comb_OSCOB] = COMBO_ACTION(OSCOB_combo),
[comb_OKAV] = COMBO_ACTION(OKAV_combo),
[comb_KAV] = COMBO(KAV_combo, S_QUOT),
[comb_CT] = COMBO(CT_combo, C_T),
[comb_GIPL] = COMBO(GIPL_combo, GIP_L),
[comb_SOH] = COMBO(SOH_combo, C_S),
[comb_CK] = COMBO(CK_combo, C_K),
[comb_CP] = COMBO(CP_combo, C_P),
[comb_CA] = COMBO(CA_combo, C_A),
[comb_RESH] = COMBO(RESH_combo, S_3),
[comb_GSS] = COMBO(GSS_combo, GIPS_S),
[comb_PER] = COMBO(PER_combo, C_PGDN),
[comb_PER2] = COMBO(PER2_combo, C_PGUP),
[comb_CSES] = COMBO(CSES_combo, C_S_ES),
[comb_F4] = COMBO(F4_combo, KC_F4),
[comb_F5] = COMBO(F5_combo, KC_F5),
[comb_F11] = COMBO(F11_combo, KC_F11),
[comb_BR] = COMBO(BR_combo, C_B),
[comb_CUP] = COMBO(CUP_combo, C_UP),
[comb_CDW] = COMBO(CDW_combo, C_DW),
[comb_CE] = COMBO(CE_combo, C_E),
[comb_SHY] = COMBO(SHY_combo, KC_RBRC),
[comb_PLUS] = COMBO(PLUS_combo, KC_PPLS),
[comb_RAV] = COMBO(RAV_combo, KC_EQL),

[comb_N_ZAP] = COMBO(N_ZAP_combo, KC_COMM),
[comb_AEQ] = COMBO(AEQ_combo, A_EQ),
[comb_N_TOCH] = COMBO(N_TOCH_combo, KC_ENT),
[comb_N_DEL] = COMBO(N_DEL_combo, KC_PSLS),
[comb_N_UMN] = COMBO(N_UMN_combo, KC_PAST),
[comb_N_MIN] = COMBO(N_MIN_combo, KC_PMNS),
[comb_N_PLUS] = COMBO(N_PLUS_combo, KC_PPLS),
[comb_N_RAV] = COMBO(N_RAV_combo, KC_EQL),
[comb_N_DT] = COMBO(N_DT_combo, S_SCLN),
[comb_N_TZ] = COMBO(N_TZ_combo, KC_SCLN),
[comb_N_DOL] = COMBO(N_DOL_combo, S_4),
[comb_N_STEP] = COMBO(N_STEP_combo, S_6),
[comb_N_MEN] = COMBO(N_MEN_combo, S_COMM),
[comb_N_BOL] = COMBO(N_BOL_combo, S_DOT),
[comb_N_KAV] = COMBO(N_KAV_combo, S_QUOT),
[comb_N_AND] = COMBO(N_AND_combo, S_7),
[comb_SOYI] = COMBO_ACTION(SOYI_combo),
[comb_PROCH] = COMBO(PROCH_combo, S_MI),
[comb_VST] = COMBO_ACTION(VST_combo),
[comb_34] = COMBO_ACTION(34_combo),
[comb_12] = COMBO_ACTION(12_combo),
[comb_13] = COMBO_ACTION(13_combo),
[comb_14] = COMBO_ACTION(14_combo),
[comb_15] = COMBO_ACTION(15_combo),
[comb_16] = COMBO_ACTION(16_combo),
[comb_20] = COMBO_ACTION(20_combo),
[comb_MON2] = COMBO_ACTION(MON2_combo),

}; // закоментировать: УПР+?

// действия для комбо
void process_combo_event(uint16_t combo_index, bool pressed) { 
  switch(combo_index) {
    case comb_ZAP: // запятая
      if (pressed) {
        tap_code(KC_COMM);
        tap_code(KC_SPC);
        comotS_active = true;
        comotS_timer = timer_read();        
      }
      break;
    case comb_TOCH:                   // открытая скобка
      if (pressed) {                  // если нажата
        tap_code(KC_DOT);             // топаем KC_DOT (точка)
        tap_code(KC_ENT);             // топаем KC_ENT (ввод)
        set_oneshot_mods(MOD_LSFT);   // активируем ожидающий РЕГ
        shift_active = true;          // активируем индикатор зажатого РЕГ
        shift_timer = timer_read();   // начать запись времени
        comotE_active = true;         // активируем индикатор ввода
        comotE_timer = timer_read();  // начать запись времени
      }
      break;      
    case comb_OSCOB:            // открытая скобка
      if (pressed) {            // если нажата
        if (!skob_active) {     // если индикатор скобки не активен
          tap_code16(S(KC_9));  // топаем S(KC_9)
          skob_active=true;     // активируем индикатор скобки
      } else {                  // если индикатор скобки активен
        tap_code16(S(KC_0));    // топаем S(KC_0)
        skob_active=false;      // деактивируем индикатор скобки
        }       
      }
      break;     
    case comb_OKAV: // открытая кавычка
      if (pressed) {
        if (!kav_active) {  //
        register_code(KC_LALT);
        tap_code(KC_P0);
        tap_code(KC_P1);
        tap_code(KC_P7);
        tap_code(KC_P1);
        unregister_code(KC_LALT);
        set_oneshot_mods(MOD_LSFT);   // активируем ожидающий РЕГ
        shift_active = true;          // активируем индикатор зажатого РЕГ
        shift_timer = timer_read();   // начать запись времени
          kav_active=true;
      } else {
        register_code(KC_LALT);
        tap_code(KC_P0);
        tap_code(KC_P1);
        tap_code(KC_P8);
        tap_code(KC_P7);
        unregister_code(KC_LALT);
        kav_active=false;
        }  
      }
      break;      
    case comb_TZ: // точка c запятой
      if (pressed) {
        tap_code(KC_SCLN);
        tap_code(KC_ENT);
        comotE_active = true;         // активируем индикатор ввода
        comotE_timer = timer_read();  // начать запись времени
      }
      break;      
    case comb_UDVS: 
      if (pressed) {
        tap_code16(C(KC_A));
        tap_code(KC_DEL);
      }
      break; 
    case comb_UDST: 
      if (pressed) {
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        unregister_code(KC_LSFT);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
      }
      break;
    case comb_DT: // двоеточие
      if (pressed) {
        tap_code16(S(KC_SCLN));
        tap_code(KC_ENT);
        comotE_active = true;         // активируем индикатор ввода
        comotE_timer = timer_read();  // начать запись времени
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
        tap_code(KC_ENT);
        set_oneshot_mods(MOD_LSFT);
        shift_active = true;
        shift_timer = timer_read();
        comotE_active = true;         // активируем индикатор ввода
        comotE_timer = timer_read();  // начать запись времени        
      }
      break;
     case comb_VOP: // ?
      if (pressed) {
        tap_code16(S(KC_SLSH));
        tap_code(KC_ENT);
        set_oneshot_mods(MOD_LSFT);
        shift_active = true;
        shift_timer = timer_read();
        comotE_active = true;         // активируем индикатор ввода
        comotE_timer = timer_read();  // начать запись времени
      }
      break; 
    case comb_REG1: // залипший Рег (левый)        
      if (pressed) {
        set_oneshot_mods(MOD_LSFT);
        shift_active = true;
        shift_timer = timer_read();
      }
      break;       
    case comb_REG2: // пробел и залипший Рег (правый)
      if (pressed) {
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_LSFT);
        shift_active = true;
        shift_timer = timer_read();
      }
 break;     

 case comb_SOYI: // _и_
      if (pressed) {
        tap_code(KC_SPC);
        tap_code(KC_I);
        tap_code(KC_SPC);
      }
      break;
    case comb_VST: // _и_
      if (pressed) {
        tap_code16(A(KC_1));
        tap_code16(A(KC_2));
      }
      break;

    case comb_PROB2: // 
      if (pressed) {
        tap_code(KC_LEFT);
        tap_code(KC_RGHT);
        tap_code(KC_SPC);
      }
      break;
    case comb_34: // 
    if (pressed) {send_string("3,14159265358979");}
    break;
    case comb_12: // 
    if (pressed) {send_string("100");}
    break;
    case comb_13: // 
    if (pressed) {send_string("1000");}
    break;
    case comb_14: // 
    if (pressed) {send_string("10000");}
    break;
    case comb_15: // 
    if (pressed) {send_string("100000");}
    break;
    case comb_16: // 
    if (pressed) {send_string("1000000");}
    break;
    case comb_20: // 
    if (pressed) {send_string("2021");}
    break;

   case comb_MON2: // 
    if (pressed) {
      register_code(KC_LGUI);
      tap_code(KC_RGHT);
      tap_code(KC_RGHT);
      tap_code(KC_UP);
      unregister_code(KC_LGUI);
    }
    break;
  }
}

typedef struct { //назначение структуры нажатий https://docs.qmk.fm/#/feature_tap_dance?id=how-to-use
    bool is_press_action;
    uint8_t state;
} tap;

uint8_t cur_dance(qk_tap_dance_state_t *state) {      // определение состояния двойного нажатия
    if (state->count == 1) {                          // если нажата один раз
        if (!state->pressed) return SINGLE_TAP;       // если отпущенна, то Одиночное нажатие
        else return SINGLE_HOLD;                      // иначе Одиночное удержание
    } else if (state->count == 2) return DOUBLE_TAP;  // если нажата два раза, то Двойное нажатие
    else return 8;                                    // магическое число (на будущее)
}
static tap ql_tap_state = {                           // инициализация двойного нажатия
    .is_press_action = true,
    .state = 0                                        // обнуление состояния
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) { // функция двойного нажатия Р/А. Действие при нажатии
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: 
        #ifdef RGBLIGHT_ENABLE            // если опция подсветки включена
          if (caps_active) {              // если индикатор caps_active активен
            rgblight_enable_noeeprom();   // включить подсветку
            } else {                      // иначе
            rgblight_disable_noeeprom();  // выключить подсветку
            }
        #endif
        register_code(KC_CAPS);
        break; // нажатие КАПС
        case SINGLE_HOLD: 
        tap_code(KC_CAPS);
        break; // нажатие КАПС
    }
}
void x_reset(qk_tap_dance_state_t *state, void *user_data) { // Действие при отпускании
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
        unregister_code(KC_CAPS); 
        break; // снятие КАПС
        case SINGLE_HOLD: 
        tap_code(KC_CAPS); 
        break;  // нажатие КАПС
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void soh_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code(KC_PAST); break;
        case DOUBLE_TAP: register_code16(C(KC_S)); break;
        case SINGLE_HOLD: register_code(KC_F12); break;
    }
}
void soh_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_PAST); break;
        case DOUBLE_TAP: unregister_code16(C(KC_S)); tap_code16(A(KC_F4)); break;
        case SINGLE_HOLD: unregister_code(KC_F12); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void vydel_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code(KC_HOME);  break;
        case DOUBLE_TAP: register_code(KC_END);  break;
        case SINGLE_HOLD: tap_code(KC_HOME); register_code(KC_LSFT);  break;
    }
}
void vydel_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_HOME); break;
        case DOUBLE_TAP: unregister_code(KC_END); break;
        case SINGLE_HOLD: tap_code(KC_END); unregister_code(KC_LSFT);  break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void kopi_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP: register_code16(C(KC_C));  break;
        case DOUBLE_TAP: register_code16(C(KC_X));  break;
        case SINGLE_HOLD: tap_code16(C(KC_A)); break;
        //case SINGLE_HOLD: tap_code16(C(KC_C)); break;
    }
}
void kopi_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code16(C(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(C(KC_X)); break;
        case SINGLE_HOLD: tap_code16(C(KC_C)); break;
        //case SINGLE_HOLD: tap_code16(C(KC_V)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void vstav_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:  tap_code16(C(KC_V));  break;
        case DOUBLE_TAP: tap_code16(C(KC_V));  break;
        case SINGLE_HOLD: tap_code16(C(KC_A)); break;
    }
}
void vstav_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: break;
        case DOUBLE_TAP: tap_code(KC_ENT); break;
        case SINGLE_HOLD: tap_code16(C(KC_V)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void VYH_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:  register_code(KC_ESC);  break;
        case DOUBLE_TAP: register_code16(A(KC_F4));  break;
        case SINGLE_HOLD: register_code16(C(KC_W)); break;
    }
}
void VYH_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_ESC); break;
        case DOUBLE_TAP: unregister_code16(A(KC_F4)); break;
        case SINGLE_HOLD: unregister_code16(C(KC_W)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void OSKOBT_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:    
        if (shift_held) {
          if (caps_active) {                                                              // если капс активен (русская раскладка)
            tap_code(KC_CAPS);                                                            // деактивировать капс (перейти на английскую раскладку)
            register_code16(S(KC_COMM));                                                            // [
            tap_code(KC_CAPS);
            } else {
            register_code16(S(KC_COMM));
            }
        }
           else {register_code16(S(KC_9));}                                                     // (
        break;
        case DOUBLE_TAP:                                                                  // при двойном нажатии
          send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_1))); // «
          break;
        case SINGLE_HOLD:                                                                 // при удержании
          if (caps_active) {                                                              // если капс активен (русская раскладка)
            tap_code(KC_CAPS);                                                            // деактивировать капс (перейти на английскую раскладку)
            tap_code(KC_LBRC);                                                            // [
            tap_code(KC_CAPS);
            } else {
            tap_code(KC_LBRC);
            }
        break;
    }
}
void OSKOBT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
          unregister_code16(S(KC_9)); unregister_code16(S(KC_COMM)); break;
        case DOUBLE_TAP: break;
        case SINGLE_HOLD: break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void ZSKOBT_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:   
        if (shift_held) {
          if (caps_active) {                                                            // если капс активен (русская раскладка)
            tap_code(KC_CAPS);                                                            // деактивировать капс (перейти на английскую раскладку)
            register_code16(S(KC_DOT));                                                            // [
            tap_code(KC_CAPS);
            } else {
            register_code16(S(KC_DOT));
            }
        }
           else {register_code16(S(KC_0));}                                                     // (
        break;
        case DOUBLE_TAP:
          send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_7)));
          break;
        case SINGLE_HOLD:
          if (caps_active) { 
            tap_code(KC_CAPS);
            tap_code(KC_RBRC);
            tap_code(KC_CAPS);
            } else {
            tap_code(KC_RBRC);
            }
        break;
    }
}
void ZSKOBT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
          unregister_code16(S(KC_0)); unregister_code16(S(KC_DOT)); break;
        case DOUBLE_TAP: break;
        case SINGLE_HOLD: break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void MINS_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
          register_code(KC_MINS);
        break;
        case DOUBLE_TAP:
          send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_1)));
          break;
        case SINGLE_HOLD:
        send_string(SS_LALT(SS_TAP(X_KP_8)SS_TAP(X_KP_7)SS_TAP(X_KP_2)SS_TAP(X_KP_2)));
        break;
    }
}
void MINS_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
          unregister_code(KC_MINS); break;
        case DOUBLE_TAP: break;
        case SINGLE_HOLD: break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void GIP_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
          tap_code16(A(KC_TAB));
        break;
        case DOUBLE_TAP:
          tap_code16(A(KC_ESC));
          break;
        case SINGLE_HOLD:
        register_code(KC_LGUI);                                // KC_LGUI в положение нажат
     gpu_active = true; 
        break;
    }
}
void GIP_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: break;
        case DOUBLE_TAP: break;
        case SINGLE_HOLD:
        unregister_code(KC_LGUI);                                // KC_LGUI в положение нажат
     gpu_active = false; 
      break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};
void POISK_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:  register_code(KC_F3);  break;
        case DOUBLE_TAP: register_code16(C(KC_F));  break;
        case SINGLE_HOLD: register_code16(C(KC_H)); break;
    }
}
void POISK_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(C(KC_F)); break;
        case SINGLE_HOLD: unregister_code16(C(KC_H)); break;
    }
    ql_tap_state.state = 0; // обнуление состояния
};

qk_tap_dance_action_t tap_dance_actions[] = { // связка кнопок с функциями двойного нажатия
    [VYH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, VYH_finished, VYH_reset), // выйти / принудительно закрыть / закрыть окно
    [POISK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, POISK_finished, POISK_reset), // поиск (продолжить) / поиск
    [OSKOBT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, OSKOBT_finished, OSKOBT_reset), // («[{
    [ZSKOBT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ZSKOBT_finished, ZSKOBT_reset), // )»]}
    [MINS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, MINS_finished, MINS_reset), // дефис, тире, минус
    [RU_AN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset), // Р/А
    [SOHR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, soh_finished, soh_reset), // сохранить / сохранить и выйти / сохранить как
    [VYDEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vydel_finished, vydel_reset), // в начало / в конец / выделить строку
    [KOP1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kopi_finished, kopi_reset),  // копировать / вырезать
    [VST1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vstav_finished, vstav_reset), // вставить / вставить и нажать ввод / удалить всё и вставить
    [GIP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, GIP_finished, GIP_reset), // вставить / вставить и нажать ввод / удалить всё и вставить
    [VOPRR] = ACTION_TAP_DANCE_DOUBLE(S(KC_SLSH), S(KC_1)),
    [SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, S(KC_SCLN)),
};

//Создание кнопок
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions#programming-the-behavior-of-any-keycode-id-programming-the-behavior-of-any-keycode
  switch (keycode) {
    case PS_1 ... PS_5:                                  // в случае нажатия кнопок с макросами
    {
      uint16_t index = keycode - PS_1;                   // задать порядковый индекс
      if (record->event.pressed) {                       // в случае нажатия
        if (caps_active) {                               // если капс активен (русская раскладка)                   
              tap_code(KC_CAPS);                         // деактивировать капс (перейти на английскую раскладку)
              send_string(paro[index]); tap_code(KC_ENT);// посылаем код макроса и топаем KC_ENT
              tap_code(KC_CAPS);
            } else {
              send_string(paro[index]); tap_code(KC_ENT);
              }
        }
      break;
    }
    case G_SP:  COD(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_5))) // неразрывный пробел
    case G_NOM:  COD(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2)))
    case G_PARA:  COD(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_1)))

    case OSM(MOD_LSFT): // в случае нажатия KC_LSFT
    case MOD_LSFT:
    case KC_LSFT:
        shift_held = record->event.pressed; // активировать индикатор РЕГ
    return true;
    break; 
    case KC_SPC:
     if (record->event.pressed & comotE_active) {
        tap_code(KC_BSPC);
        return true;  
       }
    return true;
    break; 
    case KC_ENT:
     if (record->event.pressed & comotS_active) {
        tap_code(KC_BSPC);
        return true;  
       }
    return true;
    break; 

    // в случае нажатия букв д, б, з, т, с, в 
/*    case KC_D:
    case KC_B:
    case KC_Z:
    case KC_T:
    case KC_S:
    case KC_W: 
        twz_active = true;        // активировать индикатор Ъ
        twz_timer = timer_read(); // начать запись времени индикатора Ъ
    return true;
    break; */

   // case TD(RU_AN):                                                       // в случае нажатия TD(RU_AN)(ъ или RU_AN)
   //   if (record->event.pressed) {                                        // при нажатии
    //    if (twz_active) {                                                 // если индикатор Ъ активен
    //    send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_4))); // посылаем альт-код символа ъ
    //    return false;                                                     // не выполнять основное действие нажатия
  //      } 
  //    }
  //  break;

    case KC_Y: if (record->event.pressed) {y_active = true;}
    else y_active = false;
    break;

    case KC_F15:
      if (record->event.pressed & !y_active) { 
          if (caps_active) { 
            send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_4))); // посылаем альт-код символа ъ 
/*            register_code(KC_ALGR);
            tap_code(KC_X);
            unregister_code(KC_ALGR);*/
            return false; 
            } else {
            tap_code(KC_QUOT); // посылаем '
            return false; 
            }
          }
        break;  
/*    case KC_F15:                                                             // в случае нажатия TWZ(ъ или KC_HOME)
      if (record->event.pressed & !y_active) {                                        // при нажатии
        if (!twz_active) {
          tap_code(KC_SLCK);
          return false;  
       }
          else {                                                            // если индикатор Ъ активен
        send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_4)));// посылаем альт-код символа ъ
        return false;  
        }
      }
      break;*/
    case UD_STROK: // Удалить строку
      if (record->event.pressed) {        
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        unregister_code(KC_LSFT);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
      }
    break;
    case MINMIN:
      if (record->event.pressed) {        
        tap_code(KC_PMNS);
        tap_code(KC_PMNS);
      }
    break;
    case KC_9: if (record->event.pressed) {                             // в случае нажатия KC_9: при нажатии
    if (shift_held) {                                                   // если активен индикатор РЕГ
      unregister_code(KC_LSFT);                                         // KC_LSFT в положение отпущен
      send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2))); // посылаем альт-код символа №
      return false;                                                     // не выполнять основное действие нажатия
      }
    }
    break;
    case KC_0: if (record->event.pressed) {                             // в случае нажатия KC_0: при нажатии
    if (shift_held) {                                                   // если активен индикатор РЕГ
      unregister_code(KC_LSFT);                                         // KC_LSFT в положение отпущен
      send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_1)));               // посылаем альт-код символа §
      return false;                                                     // не выполнять основное действие нажатия
      }
    }
    break;
    // Действия с клавишей ГИП
    case KC_LBRC: if (record->event.pressed) {        // в случае нажатия KC_BSLS (Э): при нажатии
    if (gpu_active) {                                 // если активен индикатор ГИП
      tap_code(KC_1);                                 // топнуть 1
      return false;                                   // не выполнять основное действие нажатия (Э)
      }
    else if (!caps_active) {       
    tap_code(KC_S); tap_code(KC_H); return false;}
    }
    break;

    case KC_NUBS: if (record->event.pressed) {           // в случае нажатия KC_Q: при нажатии
    if (gpu_active) {tap_code(KC_2); return false; }  // если активен индикатор ГИП: топнуть 3; отменить основное действие нажатия (Q)
    }
    break;
    case KC_X: if (record->event.pressed) { 
    if (gpu_active) { tap_code(KC_3); return false;}
    }
    break;

    case KC_U: if (record->event.pressed) { 
    u_active = true;
    if (gpu_active) { tap_code(KC_4); return false;}  // и ГИП, нажать клавишу 5
      }
    else u_active = false;
    break;
   case KC_F14: if (record->event.pressed) {                                   // в случае нажатия RU_E
    if (gpu_active) { tap_code(KC_5); return false;}                          // и ГИП, нажать клавишу 2
     else if (caps_active & !u_active) {
     REG_R2(tap_code16(S(KC_COMM)), tap_code16(S(KC_DOT))); }  
   // REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_1))), send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_0)))); }
 }                                                                    // иначе послать букву ё
    break;
    case KC_GRV: if (record->event.pressed) { 
    if (!caps_active) {       
    tap_code(KC_C); tap_code(KC_H); return false;}
      }
    break;
    case KC_BSLS: if (record->event.pressed) { 
    if (!caps_active) {       
    tap_code(KC_G); tap_code(KC_H); return false;}
      }
    break;

    case OTMENA: if (record->event.pressed) {                                           // в случае нажатия TD(VYDEL)
      REG_R2(tap_code16(C(KC_Z)), tap_code16(C(KC_Y)))
    }
    break;

    case KC_RESET:                    // в случае нажатия KC_RESET
      if (!record->event.pressed) {   // при отпускании
        reset_keyboard();             // перезагрузить клавиатуру для прошивки
      }
    return false;
    break;
    // Отправка альт-кодов в зависимости от положения РЕГ:
    case ZAP: REG_R2(tap_code(KC_COMM), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_4))))
    case TOCH: REG_R2(tap_code(KC_DOT), send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_6))))
    case KAVYCH: REG_R2(tap_code16(S(KC_QUOT)), tap_code(KC_QUOT))
    case SLESH: REG_R2(tap_code(KC_PSLS), send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_2))))
    case RU_TY: REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_4))), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_4))))
    case UDAR: REG_R2(send_string(SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_6))), send_string(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_6))))
    case STEPE:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_8))), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_9))))
    case GRADU:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_8))), send_string(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_6))))
    case UMNO:REG_R2(send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_5))), send_string(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_7))))
   }
  return true;
};

void matrix_scan_user(void) {                  // сканирование таймеров
  if (shift_active) {                          // если активен индикатор зажатого РЕГ 
    if (timer_elapsed(shift_timer) > 3000) {   // если прошло более ... мс // wait_ms(100);
      unregister_code(KC_LSFT);                // KC_LSFT в положение отпущен
      shift_active = false;                    // деактивировать индикатор зажатого РЕГ 
    }
  }
/*  if (twz_active) {                            // если активен индикатор Ъ
    if (timer_elapsed(twz_timer) > 1500) {     // если прошло более ... мс
      twz_active = false;                      // деактивировать индикатор Ъ
    }
  }*/
  if (comotE_active) {                            // если активен индикатор Ъ
    if (timer_elapsed(comotE_timer) > 2000) {     // если прошло более ... мс
      comotE_active = false;                      // деактивировать индикатор Ъ
    }
  }
  if (comotS_active) {                            // если активен индикатор Ъ
    if (timer_elapsed(comotS_timer) > 2000) {     // если прошло более ... мс
      comotS_active = false;                      // деактивировать индикатор Ъ
    }
  }

if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {  // если индикатор CAPS_LOCK не активен
      caps_active=true;                               // активировать индикатор caps_active (реверс)
     } else {
      caps_active=false;                              // иначе деактивировать индикатор caps_active
    }
};


#ifdef RGBLIGHT_ENABLE                        // если опция подсветки включена
void keyboard_post_init_user(void){
 if (caps_active) {                           // если индикатор caps_active активен
            rgblight_enable_noeeprom();       // включить подсветку
            } else {                          // иначе
            rgblight_disable_noeeprom();      // выключить подсветку
            }
}
#endif
