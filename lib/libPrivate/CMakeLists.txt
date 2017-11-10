add_library(libPrivate STATIC libPrivate.cpp libPrivate.h)

install(TARGETS libPrivate EXPORT basicLibTargets
    ARCHIVE DESTINATION lib)