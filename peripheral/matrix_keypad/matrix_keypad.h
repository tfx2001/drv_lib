#if !defined(__MATRIX_KEYPAD)
#define __MATRIX_KEYPAD

#include "drv_lib.h"

typedef struct {
    drv_pin_t pin_x[4];
    drv_pin_t pin_y[4];
} mat_keypad_t;

void mat_keypad_init(mat_keypad_t keypad);
void mat_keypad_get_key(void);

#endif  // __MATRIX_KEYPAD
