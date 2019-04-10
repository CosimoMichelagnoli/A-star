cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
find_package(SFML COMPONENTS system window graphics network audio)
add_executable(runGameMapTests runTest.cpp testAll.cpp)
set(TEST_SOURCE_FILES testAll.cpp runTest.cpp)


target_link_libraries(runGameMapTests gtest gtest_main core)
target_link_libraries(runGameMapTest ${SFML_LIBRARIES})
