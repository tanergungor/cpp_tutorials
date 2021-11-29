cmake_minimum_required(VERSION 2.6)

project (cpp_tutorials)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../bin/Release")
else()
    set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}")
endif()

add_subdirectory (src)
