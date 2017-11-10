add_library(libPublic OBJECT libPublic.cpp libPublic.h)

#target_include_directories(libPublic INTERFACE $<INSTALL_INTERFACE:include>)
install(FILES libPublic.h DESTINATION include)