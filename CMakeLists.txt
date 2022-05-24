cmake_minimum_required(VERSION 3.0.0)
project(ProjectAkhirAlgo-Group1 LANGUAGES C VERSION 0.1.0)

# include(CTest)
# enable_testing()

include_directories(includes)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

file(GLOB SOURCES "src/*.c")
add_executable(tiket ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
