add_library(libPrivate STATIC libPrivate.cpp libPrivate.h)

target_include_directories(libPrivate PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)