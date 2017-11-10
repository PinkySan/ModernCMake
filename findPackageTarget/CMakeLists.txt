cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(findPackageTarget VERSION 0.1 LANGUAGES CXX)

find_package(basicLib HINTS ${CMAKE_CURRENT_BINARY_DIR}/../install/lib/cmake/)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE basicLib)