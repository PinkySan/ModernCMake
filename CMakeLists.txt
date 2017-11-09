cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(PackageAndInstall VERSION 0.1 LANGUAGES CXX)
#[[
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
]]
add_subdirectory(lib)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE basicLib)