# This sample app is not dependent or depends on any other app/lib.

cmake_minimum_required(VERSION 3.5)

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(hellolib)
add_library(hello_shared SHARED hello.cpp hello.h)
add_library(hello_static STATIC hello.cpp hello.h)

set(LIB_NAME "hello")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  set(STATIC_LIB_NAME "hello_static")
else()
  set(STATIC_LIB_NAME "hello")
endif()

set_target_properties(hello_shared PROPERTIES
  OUTPUT_NAME ${LIB_NAME}
)


set_target_properties(hello_static PROPERTIES
  OUTPUT_NAME ${STATIC_LIB_NAME}
)

install(
 TARGETS
 hello_shared
 hello_static
 LIBRARY DESTINATION lib
)

install(FILES hello.h DESTINATION include)