cmake_minimum_required(VERSION 3.29)

project(binarysearchtree VERSION 1.0.1)
set(CMAKE_DEBUG_POSTFIX d)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/binarysearchtree.c)

target_include_directories(${PROJECT_NAME} PRIVATE include)


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
