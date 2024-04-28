cmake_minimum_required(VERSION 3.0.0)
project(C-Code-Dump VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

# file( GLOB APP_SOURCES RELATIVE src/*.c )
file(GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c)
# file( GLOB APP_SOURCES app/*.cxx )
foreach( testsourcefile ${APP_SOURCES} )
    # Cut off the file extension and directory path
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app

endforeach( testsourcefile ${APP_SOURCES} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
