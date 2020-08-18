cmake_minimum_required(VERSION 3.16)
project(FOMOSv1-Yellow C)

set(CMAKE_C_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_executable(FOMOSv1-Yellow FOMOS.c settings.c FOMOSUI.c restart.c shutdown.c calculator.c cHeaderFiles/calculatorButtons.h)