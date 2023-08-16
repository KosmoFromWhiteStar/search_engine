cmake_minimum_required(VERSION 3.26)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)

#Gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_disable_pthreads on)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

#Gtest

#JSON lib
add_subdirectory("${CMAKE_SOURCE_DIR}/incl/nlohmann_json")
#JSON lib

add_subdirectory(src)

set(JSON_BuildTests OFF CACHE INTERNAL "")