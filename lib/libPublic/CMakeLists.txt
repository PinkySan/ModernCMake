add_library(libPublic STATIC libPublic.cpp libPublic.h)

target_include_directories(libPublic PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>$<INSTALL_INTERFACE:include>)
install(FILES libPublic.h DESTINATION include)