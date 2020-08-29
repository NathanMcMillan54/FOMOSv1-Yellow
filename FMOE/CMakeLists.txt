cmake_minimum_required(VERSION 3.16)
project(FMOE C)

set(CMAKE_C_STANDARD 11)

add_executable(FMOE FMOE.c openFile.c makeFile.c editFile.c help.c headerFiles/openFile.h)