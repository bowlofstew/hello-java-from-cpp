cmake_minimum_required (VERSION 2.8)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)

project (CMakeHelloWorld)
include_directories(${JAVA_INCLUDE_PATH})
#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)
#indicate the entry point for the executable
add_executable (CMakeHelloWorld HelloWorld.cpp)
target_link_libraries(CMakeHelloWorld ${JNI_LIBRARIES})

install (TARGETS CMakeHelloWorld DESTINATION bin)