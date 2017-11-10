add_subdirectory(libPrivate)
add_subdirectory(libPublic)

add_library(basicLib STATIC basicLib.cpp basicLib.h)
target_link_libraries(basicLib PRIVATE libPrivate)
target_link_libraries(basicLib PUBLIC libPublic)

target_include_directories(basicLib INTERFACE $<INSTALL_INTERFACE:include>)
install(TARGETS basicLib EXPORT basicLibTargets
    ARCHIVE DESTINATION lib)
    
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_INSTALL_PREFIX}/lib/cmake/basicLibConfigVersion.cmake"
  VERSION 0.9
  COMPATIBILITY ExactVersion
)
install(EXPORT basicLibTargets
    FILE basicLibConfig.cmake
    DESTINATION lib/cmake)
    
install(FILES basicLib.h DESTINATION include)
