#if !defined(__BUTTON_H)
#define __BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "drv_lib.h"

typedef enum button_event {
    BUTTON_EVENT_PRESS_DOWN,
    BUTTON_EVENT_PRESS_UP,
    BUTTON_EVENT_LONGPRESS,
    BUTTON_EVENT_NUM,
} button_event;

typedef struct button_t {
    drv_pin_t pin;
    uint8_t   count;
    void (*cb)(struct button_t *btn, button_event e);
} button_t;

void button_init(button_t *btn);
void button_set_cb(button_t *btn, void (*callback)(button_t *, button_event));
void button_handle(button_t *btn);

#ifdef __cplusplus
}
#endif

#endif  // __BUTTON_H
