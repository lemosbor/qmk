Проверить, работает ли:
- [ ] Ё
Постоянный KC_NUMLOCK:
void matrix_init_user(void) {
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }

