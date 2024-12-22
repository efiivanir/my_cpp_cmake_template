cmake_minimum_required(VERSION 3.22)

set(MY_PROJECT Please_Change)

project(
    ${MY_PROJECT}
    VERSION 1.0.0
    LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug CACHE PATH "" FORCE)
set(CMAKE_GENERATOR "Unix Makefiles" CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/g++-14 CACHE PATH "" FORCE) 
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference" CACHE PATH "" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

set(EXECUTABLE_NAME "${MY_PROJECT}")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
#include(AddGitSubmodule)
include(FetchContent)
#include(Docs)

message(STATUS "--------------------------------------")
message(STATUS "Importing nlohmann_json")
message(STATUS "--------------------------------------")
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nlohmann_json)

message(STATUS "--------------------------------------")
message(STATUS "Importing fmt")
message(STATUS "--------------------------------------")
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 9.1.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

message(STATUS "--------------------------------------")
message(STATUS "Importing spdlog")
message(STATUS "--------------------------------------")
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.13.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

message(STATUS "--------------------------------------")
message(STATUS "Importing cxxopts")
message(STATUS "--------------------------------------")
FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.1.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cxxopts)

if(ENABLE_TESTING)
    message(STATUS "--------------------------------------")
    message(STATUS "Importing Catch2")
    message(STATUS "--------------------------------------")
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v3.5.3
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

add_subdirectory(src)
add_subdirectory(app)
if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# INSTALL TARGETS

install(
    TARGETS ${EXECUTABLE_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    TARGETS "LibFoo" "LibBar"
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
