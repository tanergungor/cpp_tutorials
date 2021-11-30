cmake_minimum_required(VERSION 3.6)

project (cpp_tutorials)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif()

set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../bin")

add_subdirectory (src)
add_subdirectory (test)
