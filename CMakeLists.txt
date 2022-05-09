cmake_minimum_required(VERSION 3.0.0)
project(ProjectAkhirAlgo-Group1 LANGUAGES C VERSION 0.1.0)

# include(CTest)
# enable_testing()

include_directories(includes)

file(GLOB SOURCES "src/*.c")
add_executable(main ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
