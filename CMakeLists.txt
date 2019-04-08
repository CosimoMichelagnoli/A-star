cmake_minimum_required(VERSION 3.10)
project(A_star)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory(test)

set(SOURCE_FILES Mappa.h Mappa.cpp MappaGrande.cpp MappaGrande.h MappaPiccola.cpp MappaPiccola.h Personaggio.h Personaggio.cpp)


add_executable(A_star main.cpp Mappa.h Mappa.cpp MappaGrande.cpp MappaGrande.h MappaPiccola.cpp MappaPiccola.h Personaggio.h Personaggio.cpp stlastar.h fsa.h MapSearchNode.cpp MapSearchNode.h test/testAll.cpp test/runTest.cpp Schermo.cpp Schermo.h Target.cpp Target.h)

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(A_star ${SFML_LIBRARIES})
endif()
target_link_libraries(A_star core)

add_library(core ${SOURCE_FILES})
