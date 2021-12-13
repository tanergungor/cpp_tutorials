cmake_minimum_required(VERSION 3.6)

project (main)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

add_subdirectory (design_patterns/singleton)
add_subdirectory (hello_world)
add_subdirectory (matrix)

# Adds an executable target called <name> to be built from the source files listed in the 
# command invocation.
add_executable (${PROJECT_NAME} main.cpp)

# The PUBLIC, PRIVATE and INTERFACE keywords can be used to specify both the link dependencies 
# and the link interface in one command. Libraries and targets following PUBLIC are linked to, 
# and are made part of the link interface. Libraries and targets following PRIVATE are linked 
# to, but are not made part of the link interface. Libraries following INTERFACE are appended 
# to the link interface and are not used for linking <target>.
target_link_libraries (${PROJECT_NAME} PUBLIC hello_world)
target_link_libraries (${PROJECT_NAME} PUBLIC matrix)

# DESTINATION specifies the directory on disk to which a file will be installed. Arguments 
# can be relative or absolute paths.
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
