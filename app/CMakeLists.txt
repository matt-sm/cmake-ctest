# This sample app depends on thirdparty/tests/test_app1 for its shared libs/headers.
# The shared libs/headers should be provided through the cache entry LIBHELLO_DIR.

cmake_minimum_required(VERSION 3.5)

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(myapp)

add_executable(myapp main.cpp)

if(DEFINED LIBHELLO_DIR)
    include_directories("${LIBHELLO_DIR}/include")
    find_library(LIBHELLO NAMES hello PATHS "${LIBHELLO_DIR}/lib")
    target_link_libraries(myapp PUBLIC ${LIBHELLO})
endif()

set_target_properties(myapp PROPERTIES
  OUTPUT_NAME myapp
)

install(
  TARGETS myapp DESTINATION bin
)