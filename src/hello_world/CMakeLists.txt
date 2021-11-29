cmake_minimum_required (VERSION 2.6)

project (hello_world)

set (CMAKE_CXX_COMPILER_WORKS ON)
set (CMAKE_CXX_COMPILER g++ CACHE STRING "C++ compiler" FORCE)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-Wall -Wextra")
set (CMAKE_CXX_FLAGS_DEBUG "-g")
set (CMAKE_CXX_FLAGS_RELEASE "-O3")

file (GLOB HEADER_FILES *.h)
file (GLOB SOURCE_FILES *.cpp)

# STATIC, SHARED, or MODULE may be given to specify the type of library to be created. 
# STATIC libraries are archives of object files for use when linking other targets. 
# SHARED libraries are linked dynamically and loaded at runtime. MODULE libraries are 
# plugins that are not linked into other targets but may be loaded dynamically at 
# runtime using dlopen-like functionality. If no type is given explicitly the type is 
# STATIC or SHARED based on whether the current value of the variable BUILD_SHARED_LIBS 
# is ON. For SHARED and MODULE libraries the POSITION_INDEPENDENT_CODE target property 
# is set to ON automatically. A SHARED library may be marked with the FRAMEWORK target 
# property to create an macOS Framework.
add_library (${PROJECT_NAME} STATIC ${SOURCE_FILES})
# Specifies include directories to use when compiling a given target. The named <target> 
# must have been created by a command such as add_executable() or add_library() and must 
# not be an ALIAS target. The INTERFACE, PUBLIC and PRIVATE keywords are required to specify 
# the scope of the following arguments. PRIVATE and PUBLIC items will populate the 
# INCLUDE_DIRECTORIES property of <target>. PUBLIC and INTERFACE items will populate the 
# INTERFACE_INCLUDE_DIRECTORIES property of <target>.
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# DESTINATION specifies the directory on disk to which a file will be installed. Arguments 
# can be relative or absolute paths.
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
install (FILES ${HEADER_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
install (FILES ${SOURCE_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
