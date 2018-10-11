cmake_minimum_required(VERSION 3.12)
add_definitions("-std=c++98 -Wall -Werror -Wextra" "-g")

macro(zob T)
    file(GLOB SRCS ${T}/*.cpp)
    add_executable(${T} ${SRCS})
    target_include_directories(${T} PRIVATE ${T})
endmacro()

zob(ex02)
#zob(ex01)
#zob(ex02)
