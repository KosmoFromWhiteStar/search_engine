cmake_minimum_required(VERSION 3.26)

set(incl_path "${CMAKE_SOURCE_DIR}/incl")


add_executable(search_engine main.cpp
               "${incl_path}/Converter_JSON.h"
                Converter_JSON.cpp
)
target_link_libraries(search_engine PUBLIC nlohmann_json::nlohmann_json)