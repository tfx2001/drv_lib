# 使用 drv_lib
set(USING_DRV_LIB 1)

# 使用的 MCU
set(MCU_USING_STM32F1 1)
set(MCU_USING_STM32F4 0)

# 使用的外设包
set(PERI_USING_MATIRX_KEYPAD 1)
set(PERI_USING_MATIRX_KEYPAD_DEBOUNCE 5)           # 消抖阈值，单位为 10ms
set(PERI_USING_MATIRX_KEYPAD_LONGPRESS 100)        # 长按阈值，单位为 10ms

set(PERI_USING_BUTTON 1)
set(PERI_USING_BUTTON_DEBOUNCE 5)           # 消抖阈值，单位为 10ms
set(PERI_USING_BUTTON_LONGPRESS 100)        # 长按阈值，单位为 10ms

if(USING_DRV_LIB)
    if(MCU_USING_STM32F1)
        set(MCU_USING_STM32 1)
    endif()
endif()
