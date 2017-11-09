cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(importTarget VERSION 0.1 LANGUAGES CXX)

add_library(libBasic STATIC IMPORTED)
set_target_properties(libBasic PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/../install/lib/basicLib.lib)
set_target_properties(libBasic PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/../install/include)
set_target_properties(libBasic PROPERTIES INTERFACE_LINK_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/../install/lib/libPublic.lib;${CMAKE_CURRENT_BINARY_DIR}/../install/lib/libPrivate.lib")
#set_target_properties(libBasic PROPERTIES INTERFACE_LINK_LIBRARIES ${CMAKE_CURRENT_BINARY_DIR}/../install/lib/libPrivate.lib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE libBasic)