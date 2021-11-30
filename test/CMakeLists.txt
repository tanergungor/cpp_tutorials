cmake_minimum_required (VERSION 3.6)

project (test_main)



include (FetchContent)
FetchContent_Declare (
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_MakeAvailable (googletest)
enable_testing ()



set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

include_directories (../src)

file (GLOB SOURCE_FILES *.cpp)

# Adds an executable target called <name> to be built from the source files listed in the 
# command invocation.
add_executable (${PROJECT_NAME} ${SOURCE_FILES})

# The PUBLIC, PRIVATE and INTERFACE keywords can be used to specify both the link dependencies 
# and the link interface in one command. Libraries and targets following PUBLIC are linked to, 
# and are made part of the link interface. Libraries and targets following PRIVATE are linked 
# to, but are not made part of the link interface. Libraries following INTERFACE are appended 
# to the link interface and are not used for linking <target>.
target_link_libraries (${PROJECT_NAME} PUBLIC gtest_main)
target_link_libraries (${PROJECT_NAME} PUBLIC matrix)

include (GoogleTest)
gtest_discover_tests (${PROJECT_NAME})

# DESTINATION specifies the directory on disk to which a file will be installed. Arguments 
# can be relative or absolute paths.
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})