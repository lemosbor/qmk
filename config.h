#pragma once // директива, для контроля за тем, чтобы файл при компиляции подключался строго один раз

#ifdef AUDIO_ENABLE //директива сообщает, что если последующий идентификатор определяется препроцессором, то выполняются все последующие директивы до первого появления #else/#endif 
    #define STARTUP_SONG SONG(ODE_TO_JOY) //определяет макрос с токеном.  После определения макроса компилятор подставит строку токена для каждого обнаруженного идентификатора
    // #define STARTUP_SONG SONG(NO_SOUND)
#endif

#define MUSIC_MASK (keycode != KC_NO) // расширяет коды клавиш для музыкального режима https://docs.qmk.fm/#/feature_audio?id=music-mask

#define LOCKING_SUPPORT_ENABLE // блокировка клавиш для капс локов
#define LOCKING_RESYNC_ENABLE // синхронизация светодиода с каспами

#define RGBLIGHT_SLEEP // если ПК в спящем режиме, то подсветка отключается
#define NO_DEBUG // отключить отладку для экономии кода

// #define AUDIO_CLICKY звук нажатия клавиши
// #define AUDIO_CLICKY_FREQ_DEFAULT 440.f // определяет частату звука нажатия клавиши

//#define MIDI_ADVANCED
/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
//qmk compile -kb preonic/rev3 -km pri
