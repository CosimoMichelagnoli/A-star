cmake_minimum_required(VERSION 3.10)

project(A_star)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Mappa.h Mappa.cpp Tile.cpp Tile.h Personaggio.h Personaggio.cpp MappaPietre.cpp MappaPietre.h MappaSiepi.cpp MappaSiepi.h )

add_executable(A_star main.cpp Mappa.h Mappa.cpp Tile.cpp Tile.h Personaggio.h Personaggio.cpp MappaPietre.cpp MappaPietre.h MappaSiepi.cpp MappaSiepi.h test/testA.h)

target_link_libraries(A_star gtest gtest_main)