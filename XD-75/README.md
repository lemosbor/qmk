- [ ] работает ли функция удержания по комбо-шифту (KEY_LOCK_ENABLE = no выключен)
- [ ] работают ли двойные нажатия. Убран блок:
uint8_t cur_dance(qk_tap_dance_state_t *state); // общая функция нажатий
void ql_finished(qk_tap_dance_state_t *state, void *user_data); //индивидуальные функции двойных нажатий
void ql_reset(qk_tap_dance_state_t *state, void *user_data);
