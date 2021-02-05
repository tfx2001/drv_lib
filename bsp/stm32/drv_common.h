#if !defined(__DRV_COMMON_H)
#define __DRV_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif  //__DRV_COMMON_H
