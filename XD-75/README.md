Проверить, работает ли:
- [ ] залипание по комбо-шифту (KEY_LOCK_ENABLE = no выключен)
- [ ] залипший комбо альт Д-Т
- [ ] двойные нажатия. Убран блок:

`uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий>`
`void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий`
`void ql_reset(qk_tap_dance_state_t *state, void *user_data);`

- [ ]  комбо (блок #define COMBO_COUNT 47 перенесен в keymap.c, заменены сочетания)
- [ ] REV_EQL (+ = в обратном порядке)
- [ ] , .
- [ ] юникод
- [ ] альт-код
- [ ] кнопка отмена
- [ ] РЕГ при удержании Ё
