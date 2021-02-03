cmake_minimum_required(VERSION 3.7)

include(${CMAKE_CURRENT_SOURCE_DIR}/drv_config.cmake)
configure_file(drv_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/drv_config.h)

set(SOURCES "")

include(bsp/bsp.cmake)

list(APPEND SOURCES drv_lib.c)
add_library(drv_lib STATIC ${SOURCES})

get_property(DRV_LIB_INCLUDE DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
target_include_directories(drv_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} driver ${DRV_LIB_INCLUDE})
