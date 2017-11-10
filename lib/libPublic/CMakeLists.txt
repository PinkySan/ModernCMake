add_library(libPublic STATIC libPublic.cpp libPublic.h)

target_include_directories(libPublic PUBLIC $<INSTALL_INTERFACE:include>)
install(FILES libPublic.h DESTINATION include)
install(TARGETS libPublic DESTINATION lib)