cmake_minimum_required(VERSION 3.17)
project(Labo3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo3 main.cpp affichage.cpp affichage.h date.cpp date.h)