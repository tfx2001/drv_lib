#include "button.h"

void button_init(button_t *btn) {
    gpio_mode(btn->pin, DRV_PIN_MODE_INPUT_PU);

    btn->count = 0;
    btn->cb    = NULL;
}

void button_set_cb(button_t *btn, void (*callback)(button_t *, button_event)) {
    btn->cb = callback;
}

/**
 * @brief 矩阵键盘处理函数，需 10ms 调用一次
 *
 * @param btn 矩阵键盘指针
 */
void button_handle(button_t *btn) {
    /* 检查回调函数指针 */
    if (btn->cb == NULL) {
        return;
    }

    if (gpio_read(btn->pin)) {
        /* 是否为按键弹起 */
        if (btn->count >= PERI_USING_BUTTON_DEBOUNCE) {
            btn->cb(btn, BUTTON_EVENT_PRESS_UP);
        }
        btn->count = 0;
    } else {
        btn->count = btn->count < 255 ? btn->count + 1 : 255;

        /* 判断长按短按 */
        if (btn->count == PERI_USING_BUTTON_DEBOUNCE) {
            btn->cb(btn, BUTTON_EVENT_PRESS_DOWN);
        } else if (btn->count == PERI_USING_BUTTON_LONGPRESS) {
            btn->cb(btn, BUTTON_EVENT_LONGPRESS);
        }
    }
}
