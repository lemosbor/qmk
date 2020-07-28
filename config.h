#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(ODE_TO_JOY)
    // #define STARTUP_SONG SONG(NO_SOUND)

#endif

#define MUSIC_MASK (keycode != KC_NO)

#define LOCKING_SUPPORT_ENABLE
#define MUSIC_MASK (keycode != KC_NO)
#define UNICODE_TYPE_DELAY 0
#define UNICODE_KEY_WINC KC_RGUI
#define UNICODE_SELECTED_MODES UC_WINC
#define RGBLIGHT_SLEEP // если ПК в спящем режиме, то подсветка не горит
#define NO_DEBUG // отключить отладку
/*#define BACKLIGHT_LEVELS 3*/

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

#define BACKLIGHT_LED_COUNT 2
#undef BACKLIGHT_PIN
#define BACKLIGHT_PINS { F5, B2 }

/*#define AUDIO_CLICKY -добавляет звук нажатия
 #define AUDIO_CLICKY_FREQ_DEFAULT 440.f */

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
//qmk compile -kb preonic/rev3 -km pri
