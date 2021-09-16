cmake_minimum_required(VERSION 3.16)

if (WIN32)
    # only linux supported so far
    message(INFO "You are using Windows. Proceed at your own risk!")
endif (WIN32)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In-source builds are not allowed.")
endif()

project(filterlib LANGUAGES CXX)
message("---------- ${PROJECT_NAME} start ----------")

# Set output directory
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# Should not be neccessary according to docs, but it is -> bug?
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
message(STATUS "${PROJECT_NAME} output: ${RUNTIME_OUTPUT_DIRECTORY}")

# ##############################################################################
# Configure the libraries
# ##############################################################################

message(STATUS "Setting up libraries ...")

# setup googletest (http://google.github.io/googletest/quickstart-cmake.html)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

message(STATUS "Setting up libraries - done")

# ##############################################################################
# Configure project sources
# ##############################################################################

set(FILTERLIB_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sources)

# Project Headers
set(FILTERLIB_HEADERS
    ${FILTERLIB_SOURCES_DIR}/biquad.h
    ${FILTERLIB_SOURCES_DIR}/butterworth.h
    ${FILTERLIB_SOURCES_DIR}/filter_design.h
    ${FILTERLIB_SOURCES_DIR}/utils.h
)

# Project Sources
set(FILTERLIB_SOURCES
    ${FILTERLIB_SOURCES_DIR}/biquad.cpp
    ${FILTERLIB_SOURCES_DIR}/butterworth.cpp
    ${FILTERLIB_SOURCES_DIR}/filter_design.cpp
    ${FILTERLIB_SOURCES_DIR}/utils.cpp
)

# These directories include the header files we want to #include <LIB>_INCLUDE
include_directories(
    ${FILTERLIB_SOURCES_DIR}
)

# add the library
add_library(filterlib ${FILTERLIB_HEADERS} ${FILTERLIB_SOURCES})
# add the executables
add_executable(example  ${FILTERLIB_SOURCES_DIR}/example.cpp)
target_link_libraries(example filterlib)

# add the tests (using google-test)
enable_testing()
add_executable(
    filter_tests
    ${FILTERLIB_SOURCES_DIR}/butterworth_tests.cpp
    ${FILTERLIB_SOURCES_DIR}/biquad_tests.cpp
    ${FILTERLIB_SOURCES_DIR}/filter_design_tests.cpp
    ${FILTERLIB_SOURCES_DIR}/utils_tests.cpp
)
target_link_libraries(
    filter_tests
    gtest_main
    filterlib
)
include(GoogleTest)
gtest_discover_tests(filter_tests)

# ##############################################################################
# Configure Compiler
# ##############################################################################

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


message("---------- ${PROJECT_NAME} finish ----------")