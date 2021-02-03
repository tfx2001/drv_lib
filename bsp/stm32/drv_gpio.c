#include "drv_gpio.h"

void gpio_init(void) {
#ifdef GPIOA
    __HAL_RCC_GPIOA_CLK_ENABLE();
#endif  // GPIOA
#ifdef GPIOB
    __HAL_RCC_GPIOB_CLK_ENABLE();
#endif  // GPIOB
#ifdef GPIOC
    __HAL_RCC_GPIOC_CLK_ENABLE();
#endif  // GPIOC
#ifdef GPIOD
    __HAL_RCC_GPIOD_CLK_ENABLE();
#endif  // GPIOD
#ifdef GPIOE
    __HAL_RCC_GPIOE_CLK_ENABLE();
#endif  // GPIOE
#ifdef GPIOF
    __HAL_RCC_GPIOF_CLK_ENABLE();
#endif  // GPIOF
#ifdef GPIOG
    __HAL_RCC_GPIOG_CLK_ENABLE();
#endif  // GPIOG
}

void gpio_mode(drv_pin_t pin, drv_pin_mode mode) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin   = pin.pin;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

    switch (mode) {
        case DRV_PIN_MODE_OUTPUT:
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
            break;
        case DRV_PIN_MODE_OUTPUT_OD:
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
            break;
        case DRV_PIN_MODE_INPUT:
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            break;
        case DRV_PIN_MODE_INPUT_PU:
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            GPIO_InitStruct.Pull = GPIO_PULLUP;
            break;
        case DRV_PIN_MODE_INPUT_PD:
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            GPIO_InitStruct.Pull = GPIO_PULLDOWN;
            break;
    }
    HAL_GPIO_Init((GPIO_TypeDef *)pin.port, &GPIO_InitStruct);
}

void gpio_write(drv_pin_t pin, uint8_t value) {
    HAL_GPIO_WritePin((GPIO_TypeDef *)pin.port, pin.pin, value);
}

uint8_t gpio_read(drv_pin_t pin) {
    return HAL_GPIO_ReadPin((GPIO_TypeDef *)pin.port, pin.pin);
}
