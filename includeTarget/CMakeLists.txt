cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(includeTarget VERSION 0.1 LANGUAGES CXX)

include(${CMAKE_CURRENT_BINARY_DIR}/../install/lib/cmake/basicLibTargets.cmake)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE basicLib)