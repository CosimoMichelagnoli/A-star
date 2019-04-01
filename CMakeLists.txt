cmake_minimum_required(VERSION 3.10)
project(A_star)

set(CMAKE_CXX_STANDARD 11)

add_executable(A_star main.cpp Mappa.h Mappa.cpp Tile.cpp Tile.h MappaGrande.cpp MappaGrande.h MappaPiccola.cpp MappaPiccola.h Personaggio.h Personaggio.cpp stlastar.h fsa.h MapSearchNode.cpp MapSearchNode.h)