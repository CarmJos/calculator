cmake_minimum_required(VERSION 3.28)
project(calculator C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.runtime)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.library)

include_directories(include)
add_compile_options(${GTKMM_CFLAGS_OTHER})
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(calculator
        src/main.c
        src/calculator.c
        src/callback.c
        src/interface.c
)
target_link_libraries(calculator PUBLIC PkgConfig::GTK4)

# 添加安装目标
install(TARGETS calculator DESTINATION bin)

# 包含CPack模块
include(CPack)

# 配置CPack
set(CPACK_PACKAGE_NAME "calculator")
set(CPACK_PACKAGE_VENDOR "CarmJos")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Calculator Application")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "calculator")

set(CPACK_GENERATOR "ZIP")

# 启用CPack
cpack_add_component(calculator
        DISPLAY_NAME "Calculator Application"
        DESCRIPTION "A lightweight & simple calculator application that can perform basic arithmetic operations, based on C11 language."
        REQUIRED
)