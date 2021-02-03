if(PERI_USING_MATIRX_KEYPAD)
    message(STATUS "Using matrix_keypad")
    include(peripheral/matrix_keypad/matrix_keypad.cmake)
endif()
