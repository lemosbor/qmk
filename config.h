#pragma once // директива, для контроля за тем, чтобы файл при компиляции подключался строго один раз

//#ifdef AUDIO_ENABLE //директива сообщает, что если последующий идентификатор определяется препроцессором, то выполняются все последующие директивы до первого появления #else/#endif 
  //  #define STARTUP_SONG SONG(PREONIC_SOUND) //определяет макрос с токеном.  После определения макроса компилятор подставит строку токена для каждого обнаруженного идентификатора
    // #define STARTUP_SONG SONG(NO_SOUND)
//#endif

#define MUSIC_MASK (keycode != KC_NO) // расширяет коды клавиш для музыкального режима https://docs.qmk.fm/#/feature_audio?id=music-mask

#define LOCKING_SUPPORT_ENABLE // блокировка клавиш для капс локов
#define LOCKING_RESYNC_ENABLE // синхронизация светодиода с каспами

#undef  BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 1 //яркость светодиодов

#define CUSTOM_STARTUP \
    QD_NOTE(_A6),  \
    QD_NOTE(_C7),  \
    QD_NOTE(_A7),  \
    QD_NOTE(_F7),  \
    QD_NOTE(_G7),  \
    HD_NOTE(_C8),

#define RGBLIGHT_SLEEP // если ПК в спящем режиме, то подсветка отключается
#define NO_DEBUG // отключить отладку для экономии кода

#define TAPPING_TERM 200 // задержка для клавиш двойного назначения

// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
#define COMBO_TERM 25 // задержка для комбо
#define COMBO_COUNT 25 // количество спец. комбинаций с клавишами

//#define AUTO_SHIFT_MODIFIERS // автоматический шифт
//#define AUTO_SHIFT_TIMEOUT 150 // время необходимого удержания для авто-шифта

//#define UNICODE_KEY_WINC KC_LALT
//#define UNICODE_KEY_WIN KC_LALT
//#define UNICODE_SELECTED_MODES UC_WIN


// #define AUDIO_CLICKY звук нажатия клавиши
// #define AUDIO_CLICKY_FREQ_DEFAULT 440.f // определяет частату звука нажатия клавиши

//#define MIDI_ADVANCED
/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
//qmk compile -kb preonic/rev3 -km pri
