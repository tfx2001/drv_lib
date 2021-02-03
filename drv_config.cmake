# 使用 drv_lib
set(USING_DRV_LIB 1)

# 使用的 MCU
set(MCU_USING_STM32F1 1)

# 使用的外设包
set(PERI_USING_MATIRX_KEYPAD 1)

if(USING_DRV_LIB)
    if(MCU_USING_STM32F1)
        set(MCU_USING_STM32 1)
    endif()
endif()
