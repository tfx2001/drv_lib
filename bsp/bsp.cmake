if(MCU_USING_STM32)
    message(STATUS "Using STM32")
    include(bsp/stm32/stm32.cmake)
endif()
