#if !defined(__DRV_LIB_H)
#define __DRV_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "drv_config.h"

#include "drv_common.h"
#include "drv_gpio.h"

void drv_lib_init(void);

#ifdef __cplusplus
}
#endif

#endif  // __DRV_LIB_H
