add_subdirectory(libPrivate)
add_subdirectory(libPublic)

add_library(basicLib STATIC basicLib.cpp basicLib.h)
target_link_libraries(basicLib PRIVATE libPrivate)
target_link_libraries(basicLib PUBLIC libPublic)

target_include_directories(basicLib PUBLIC $<INSTALL_INTERFACE:include>)
install(FILES basicLib.h DESTINATION include)