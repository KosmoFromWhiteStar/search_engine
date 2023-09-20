cmake_minimum_required(VERSION 3.25.2)

project(Qt_vers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Qt_vers qt_main.cpp qt_main.h
        "${incl_path}/Converter_JSON.h"
        "${src_path}/Converter_JSON.cpp"
        "${incl_path}/Inverted_Index.h"
        "${src_path}/Inverted_Index.cpp"
        "${incl_path}/Search_Server.h"
        "${src_path}/Search_Server.cpp"
        )
target_link_libraries(Qt_vers
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        nlohmann_json::nlohmann_json)
