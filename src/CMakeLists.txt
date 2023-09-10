cmake_minimum_required(VERSION 3.25.2)

set(incl_path "${CMAKE_SOURCE_DIR}/incl")
set(test_path "${CMAKE_SOURCE_DIR}/tests")

add_executable(search_engine
            test.cpp
            "${incl_path}/Converter_JSON.h"
            Converter_JSON.cpp
            "${incl_path}/Inverted_Index.h"
            Inverted_Index.cpp
            "${incl_path}/Search_Server.h"
            Search_Server.cpp
            "${test_path}/gTest_Index.h"
            "${test_path}/gTest_Searc.h"
            )


target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(search_engine PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(search_engine)
