cmake_minimum_required(VERSION 3.21)
project(asm C)
add_subdirectory(src)
set(CMAKE_C_STANDARD 99)

add_executable(asm main.c include/system_parse.h)
target_link_libraries(asm PUBLIC bor m)
target_include_directories(asm PUBLIC "${PROJECT_SOURCE_DIR}/include")
