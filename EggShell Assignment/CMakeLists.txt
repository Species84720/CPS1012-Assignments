cmake_minimum_required(VERSION 3.13)
project(Assignment C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment main.c header.h tinyShell.c linenoise-master/linenoise.h linenoise-master/linenoise.c Controllers.c Printing.c external.c VariableHandlers.c TextHandlers.c FileHandling.c)