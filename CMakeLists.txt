cmake_minimum_required(VERSION 3.10)
project(A_star)

set(CMAKE_CXX_STANDARD 11)

add_executable(A_star main.cpp Mappa.h Mappa.cpp Tile.cpp Tile.h Personaggio.cpp Personaggio.h)