cmake_minimum_required(VERSION 3.26)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest.git)

add_subdirectory("${CMAKE_SOURCE_DIR}/incl/nlohmann_json")
add_subdirectory(src)



set(JSON_BuildTests OFF CACHE INTERNAL "")