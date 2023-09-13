cmake_minimum_required(VERSION 3.25.2)
project(test)

#Gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_disable_pthreads ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#enable_testing()
#Gtest

add_executable(test
        "${test_path}/test.cpp"
        "${incl_path}/Converter_JSON.h"
        ${src_path}/Converter_JSON.cpp
        "${incl_path}/Inverted_Index.h"
        ${src_path}/Inverted_Index.cpp
        "${incl_path}/Search_Server.h"
        ${src_path}/Search_Server.cpp
        "${test_path}/gTest_Index.h"
        "${test_path}/gTest_Searc.h"
        )

target_link_libraries(test PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(test PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(test)