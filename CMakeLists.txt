cmake_minimum_required(VERSION 3.7)

project(drv_lib LANGUAGES C)

if(${drv_lib_SOURCE_DIR} STREQUAL ${drv_lib_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/drv_config.cmake)
configure_file(drv_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/drv_config.h)

set(SOURCES "")

include(bsp/bsp.cmake)
include(peripheral/peripheral.cmake)

list(APPEND SOURCES drv_lib.c)
add_library(drv_lib STATIC ${SOURCES})

get_property(DRV_LIB_INCLUDE DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
target_include_directories(drv_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} inc ${DRV_LIB_INCLUDE})
