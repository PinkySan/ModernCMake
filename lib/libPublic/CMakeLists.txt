add_library(libPublic STATIC libPublic.cpp libPublic.h)

target_include_directories(libPublic INTERFACE $<INSTALL_INTERFACE:include>)
install(TARGETS libPublic
    ARCHIVE DESTINATION lib)
install(FILES libPublic.h DESTINATION include)