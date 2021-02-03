target_include_directories(drv_lib PUBLIC "bsp/stm32/"
                                          "bsp/stm32/STM32CubeF1/Drivers/CMSIS/Core/Include"
                                          "bsp/stm32/STM32CubeF1/Drivers/CMSIS/Device/ST/STM32F1xx/Include"
                                          "bsp/stm32/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Inc"
                                          "bsp/stm32/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy")

target_sources(drv_lib PRIVATE "bsp/stm32/drv_gpio.c"
                               "bsp/stm32/drv_common.c")
