#pragma once // директива, для контроля за тем, чтобы файл при компиляции подключался строго один раз

//#ifdef AUDIO_ENABLE //директива сообщает, что если последующий идентификатор определяется препроцессором, то выполняются все последующие директивы до первого появления #else/#endif 
  //  #define STARTUP_SONG SONG(PREONIC_SOUND) //определяет макрос с токеном.  После определения макроса компилятор подставит строку токена для каждого обнаруженного идентификатора
    // #define STARTUP_SONG SONG(NO_SOUND)
//#endif

//#define MUSIC_MASK (keycode != KC_NO) // расширяет коды клавиш для музыкального режима https://docs.qmk.fm/#/feature_audio?id=music-mask
#define LOCKING_SUPPORT_ENABLE // блокировка клавиш для капс локов
#define LOCKING_RESYNC_ENABLE // синхронизация светодиода с каспами

// #undef  BACKLIGHT_LEVELS
//#define BACKLIGHT_LEVELS 1 //яркость светодиодов

#define CUSTOM_STARTUP ED_NOTE(_E7), E__NOTE(_CS7), E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7), E__NOTE(_CS7), E__NOTE(_E6), E__NOTE(_A6), M__NOTE(_CS7, 20),

#define RGBLIGHT_SLEEP // если ПК в спящем режиме, то подсветка отключается
#define NO_DEBUG // отключить отладку для экономии кода

#define TAPPING_TERM 200 // задержка для клавиш двойного назначения
// #define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD // ускорение двойного нажатия
#define COMBO_TERM 20 // задержка для комбо
#define COMBO_COUNT 56 // количество спец. комбинаций с клавишами
#define COMBO_ALLOW_ACTION_KEY

#define ONESHOT_TAP_TOGGLE 2 // ожидающие кнопки. Количество нажатий для залипания.
#define ONESHOT_TIMEOUT 3000  // ожидающие кнопки. время ожидания (мс)

#define ENCODERS_PAD_A { B12 } // определение энкодера
#define ENCODERS_PAD_B { B13 }
#define ENCODER_RESOLUTION 1 // размерность шага

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
