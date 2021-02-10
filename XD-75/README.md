Проверить, работает ли:
- [ ] цифровые комбо: N_MEN_combo и N_BOL_combo. Если не работают, то сделать COMBO_ACTION
- [ ] Ё
Постоянный KC_NUMLOCK:
void matrix_init_user(void) {
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }

- [X] работает ли новая функция REG_R2. Если да, то сделать функцию для комбо
- [X] работают ли X_KP_1 при выключенном NUM: нет
- [X] Шведская схема: работает
- [X] Контр-Альт-Дел: работает
- [X] <>: работает
- [X] все функциональные клавиши: работают
- [X] набор пароля: работает 
- [X] альт-Ф2: работает
- [X] комбо (блок #define COMBO_COUNT 47 перенесен в keymap.c, заменены сочетания) Не работает.
- [X] REV_EQL (+ = в обратном порядке) Не работает.
- [X] кнопка отмена через Альт + BS Не везде работает.

Сделать: 
Заедает ц
Не работает светодиод
добавить знаки:
0178	²			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_8)), // ²
0179	³			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_9)), // ³

248	°			SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_8)), // °
26	→			SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_6)), // →

0215	×			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_5)), // ×
0247	÷			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_7)), // ÷

916	Δ			SS_LALT(SS_TAP(X_KP_9)SS_TAP(X_KP_1)SS_TAP(X_KP_6)), // Δ
0216	Ø			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_6)), // Ø

0187	»			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_7)), // »
0171	«			SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_1)), // «
