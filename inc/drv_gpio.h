#if !defined(__DRV_GPIO_H)
#define __DRV_GPIO_H

#include "drv_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    drv_base_t port;
    drv_base_t pin;
} drv_pin_t;

typedef enum {
    DRV_PIN_MODE_OUTPUT,
    DRV_PIN_MODE_OUTPUT_OD,
    DRV_PIN_MODE_INPUT,
    DRV_PIN_MODE_INPUT_PU,
    DRV_PIN_MODE_INPUT_PD,
} drv_pin_mode;

void    gpio_init(void);
void    gpio_mode(drv_pin_t pin, drv_pin_mode mode);
void    gpio_write(drv_pin_t pin, uint8_t value);
uint8_t gpio_read(drv_pin_t pin);
void    gpio_attach_irq(drv_pin_t pin, uint32_t mode, void (*callback)(void *args), void *args);
void    gpio_irq_enable(drv_pin_t pin, bool enabled);

#ifdef __cplusplus
}
#endif

#endif  // __DRV_GPIO_H
