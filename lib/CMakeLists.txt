add_subdirectory(libPrivate)
add_subdirectory(libPublic)

add_library(basicLib STATIC basicLib.cpp basicLib.h
     $<TARGET_OBJECTS:libPrivate>
     $<TARGET_OBJECTS:libPublic>
     )

target_include_directories(basicLib PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libPrivate>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libPublic>
    )
    
install(TARGETS basicLib EXPORT basicLibTarget
    ARCHIVE DESTINATION lib)
install(EXPORT basicLibTarget DESTINATION lib/cmake)
install(FILES basicLib.h DESTINATION include)