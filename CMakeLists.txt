cmake_minimum_required(VERSION 3.17)
project(untitled2 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled2 main.c stroke.c stroke.h shape.c shape.h util.c util.h)
target_link_libraries(untitled2 /usr/lib/libXbgi.a X11 m)