#pragma once
#define LOCKING_SUPPORT_ENABLE // блокировка клавиш для капс локов
#define LOCKING_RESYNC_ENABLE // синхронизация светодиода с каспами

#define TAPPING_TERM 200 // задержка для клавиш двойного назначения
#define PERMISSIVE_HOLD  // ускорение двойного нажатия
// #define PERMISSIVE_HOLD_PER_KEY //  усорение двойного нажатия под каждую кнопку
#define COMBO_COUNT 48 // кол-во комобо-команд
#define COMBO_TERM 20 // задержка для комбо
//#define COMBO_COUNT 47 // количество спец. комбинаций с клавишами
#define COMBO_ALLOW_ACTION_KEY

#define ONESHOT_TAP_TOGGLE 2 // ожидающие кнопки. Количество нажатий для залипания.
#define ONESHOT_TIMEOUT 2000  // ожидающие кнопки. время ожидания (мс)
