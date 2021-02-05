if(PERI_USING_MATIRX_KEYPAD)
    message(STATUS "Using matrix_keypad")
    include(peripheral/matrix_keypad/matrix_keypad.cmake)
endif()

if(PERI_USING_BUTTON)
    message(STATUS "Using button")
    include(peripheral/button/button.cmake)
endif()
