# drv_lib

这是一个面向 Cortex-M 平台的 MCU 驱动框架，统一了外设 API，以实现 MCU 平台的解耦。

## Getting Start

本项目使用 `CMake` 编译成静态链接库，使用时需在父项目的 `CMakeLists.txt` 中加入:

```cmake
include_directories(<directory_of_stm32f1xx_hal_conf.h>)
add_subdirectory(<path_to_drv_lib>)
target_link_libraries(${PROJECT_NAME}.elf drv_lib)
```

如需修改配置，请修改 `drv_config.cmake` 文件。
