cmake_minimum_required(VERSION 3.25.2)

add_executable(search_engine
            main.cpp
            "${incl_path}/Converter_JSON.h"
            Converter_JSON.cpp
            "${incl_path}/Inverted_Index.h"
            Inverted_Index.cpp
            "${incl_path}/Search_Server.h"
            Search_Server.cpp
            )

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
