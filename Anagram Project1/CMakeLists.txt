cmake_minimum_required(VERSION 3.15)
project(tryerror C)

set(CMAKE_C_STANDARD 11)

        add_executable(tryerror main.c read.c read.h Sorting.c Sorting.h anagram.c anagram.h)