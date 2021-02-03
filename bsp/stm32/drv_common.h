#if !defined(__DRV_COMMON_H)
#define __DRV_COMMON_H

#include <stdint.h>
#include <stdbool.h>

#include "drv_config.h"

// clang-format off
#if defined (MCU_USING_STM32F1)
  #include "stm32f1xx_hal.h"
#endif
// clang-format on

typedef uint32_t drv_base_t;

void drv_delay(uint32_t ms);
void drv_us_delay(uint32_t us);

#endif  //__DRV_COMMON_H
