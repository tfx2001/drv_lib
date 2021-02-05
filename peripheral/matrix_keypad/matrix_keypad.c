#include "matrix_keypad.h"

#include <string.h>

void mat_keypad_init(mat_keypad_t *keypad) {
    for (int i = 0; i < 4; i++) {
        gpio_mode(keypad->pin_x[i], DRV_PIN_MODE_OUTPUT);
        gpio_mode(keypad->pin_y[i], DRV_PIN_MODE_OUTPUT);

        gpio_write(keypad->pin_x[i], 1);
    }

    memset(keypad->count, 0, sizeof(keypad->count));
    keypad->cb = NULL;
}

void mat_keypad_set_cb(mat_keypad_t *keypad, void (*callback)(mat_keypad_t *, uint8_t, mat_keypad_event)) {
    keypad->cb = callback;
}

static uint8_t _get_x_value(mat_keypad_t *keypad) {
    uint8_t value = 0;

    for (int i = 0; i < 4; i++) {
        value |= gpio_read(keypad->pin_x[i]) << i;
    }
    return value;
}

static void _set_y_value(mat_keypad_t *keypad, uint8_t value) {
    for (int i = 0; i < 4; i++) {
        gpio_write(keypad->pin_y[i], (value >> i) & 0x01);
    }
}

/**
 * @brief 矩阵键盘处理函数，需 10ms 调用一次
 * 
 * @param keypad 矩阵键盘指针
 */
void mat_keypad_handle(mat_keypad_t *keypad) {
    const uint8_t y_value[4] = {0x0E, 0x0D, 0x0B, 0x07};
    uint8_t       x_value;

    /* 检查回调函数指针 */
    if (keypad->cb == NULL) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        _set_y_value(keypad, y_value[i]);
        x_value = _get_x_value(keypad);

        for (int j = 0; j < 4; j++) {
            /* 没按下 */
            if ((x_value >> j) & 0x01) {
                /* 是否为按键弹起 */
                if (keypad->count[i * 4 + j] >= PERI_USING_MATIRX_KEYPAD_DEBOUNCE) {
                    keypad->cb(keypad, i * 4 + j, MAT_KEYPAD_EVENT_PRESS_UP);
                }
                keypad->count[i * 4 + j] = 0;
            }
            /* 被按下 */
            else {
                keypad->count[i * 4 + j] = keypad->count[i * 4 + j] < 255 ? keypad->count[i * 4 + j] + 1 : 255;

                /* 判断长按短按 */
                if (keypad->count[i * 4 + j] == PERI_USING_MATIRX_KEYPAD_DEBOUNCE) {
                    keypad->cb(keypad, i * 4 + j, MAT_KEYPAD_EVENT_PRESS_DOWN);
                } else if (keypad->count[i * 4 + j] == PERI_USING_MATIRX_KEYPAD_LONGPRESS) {
                    keypad->cb(keypad, i * 4 + j, MAT_KEYPAD_EVENT_LONGPRESS);
                }
            }
        }
    }
}
