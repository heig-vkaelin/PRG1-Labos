cmake_minimum_required(VERSION 3.17)
project(Labo4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo4 main.cpp outils_affichage.cpp outils_affichage.h outils_jeu_vie.cpp outils_jeu_vie.h)