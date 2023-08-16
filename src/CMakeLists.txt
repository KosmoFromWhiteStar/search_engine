cmake_minimum_required(VERSION 3.26)

set(incl_path "${CMAKE_SOURCE_DIR}/incl")


add_executable(search_engine main.cpp
                "${incl_path}/Converter_JSON.h"
                Converter_JSON.cpp
                "${incl_path}/Inverted_Index.h"
                Inverted_Index.cpp
)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(search_engine PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(search_engine)
