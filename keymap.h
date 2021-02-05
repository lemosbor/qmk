#pragma once
#include "quantum.h"

void add_to_prev(uint16_t kc);
void unreg_prev(void);

#define SVIT(bt1, s1, bt2, s2, bt3, s3, bt4, s4) \
if (record->event.pressed) { \
  if (shift_held) { \
     if (alt_held) { \
      unregister_code(KC_F15); \
      if (s4 == 0) { \
        unregister_code(KC_LSFT); \
        tap_code(bt4); \
        add_to_prev(bt4); \
      } else { \
        tap_code(bt4); \
        add_to_prev(bt4); \
        unregister_code(KC_LSFT); \
       } \
    } else { \
      if (s2 == 0) { \
        unregister_code(KC_LSFT); \
        tap_code(bt2); \
      } else { \
        tap_code(bt2); \
        unregister_code(KC_LSFT); \
      } \
    } \
  } else { \
    if (alt_held) { \
      if (s3 == 0) { \
        tap_code(bt3); \
      } else { \
        register_code(KC_LSFT); \
        tap_code(bt3); \
        unregister_code(KC_LSFT); \
      } \
      unregister_code(KC_F15); \
    } else { \
      if (s1 == 0) { \
        tap_code(bt1); \
      } else { \
        register_code(KC_LSFT); \
        tap_code(bt1); \
        unregister_code(KC_LSFT); \
      } \
    } \
  } \
} \
return false;

#define KC_A 0x04
