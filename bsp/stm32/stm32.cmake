target_include_directories(drv_lib PUBLIC "bsp/stm32/")

target_sources(drv_lib PRIVATE "bsp/stm32/drv_gpio.c" "bsp/stm32/drv_common.c")
