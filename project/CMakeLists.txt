cmake_minimum_required(VERSION 3.20)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(project main.c klein64.h kleinSbox.h kleinAttack.c kleinAttack.h klein64.c)
