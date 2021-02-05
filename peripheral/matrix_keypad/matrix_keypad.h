#if !defined(__MATRIX_KEYPAD_H)
#define __MATRIX_KEYPAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "drv_lib.h"

typedef enum mat_keypad_event {
    MAT_KEYPAD_EVENT_PRESS_DOWN,
    MAT_KEYPAD_EVENT_PRESS_UP,
    MAT_KEYPAD_EVENT_LONGPRESS,
    MAT_KEYPAD_EVENT_NUM,
} mat_keypad_event;

typedef struct mat_keypad_t {
    drv_pin_t pin_x[4];
    drv_pin_t pin_y[4];

    uint8_t count[16];
    void (*cb)(struct mat_keypad_t *keypad, uint8_t key, mat_keypad_event e);
} mat_keypad_t;

void mat_keypad_init(mat_keypad_t *keypad);
void mat_keypad_set_cb(mat_keypad_t *keypad, void (*callback)(mat_keypad_t *, uint8_t, mat_keypad_event));
void mat_keypad_handle(mat_keypad_t *keypad);

#ifdef __cplusplus
}
#endif

#endif  // __MATRIX_KEYPAD_H
