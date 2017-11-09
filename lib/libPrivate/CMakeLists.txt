add_library(libPrivate STATIC libPrivate.cpp libPrivate.h)

install(TARGETS libPrivate
    ARCHIVE DESTINATION lib)