cmake_minimum_required(VERSION 3.17)
project(Labo2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo2 main.cpp exercices.h Ex1.cpp Ex2.cpp)