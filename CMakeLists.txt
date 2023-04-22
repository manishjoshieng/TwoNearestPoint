cmake_minimum_required(VERSION 3.0.0)
project(TwoNearestPoint VERSION 0.1.0)

include(CTest)
enable_testing()

# Set variables for the directories containing header files and source files
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(TwoNearestPoint 
    main.cpp
    ${SRC_DIR}/TwoNearestPoint.cc
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
