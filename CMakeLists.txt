cmake_minimum_required(VERSION 3.16)
project(FOMOSv1-Yellow C)

set(CMAKE_C_STANDARD 11)

add_executable(FOMOSv1-Yellow FOMOS.c settings.c time.c)