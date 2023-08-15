cmake_minimum_required(VERSION 3.26)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(${CMAKE_SOURCE_DIR}/incl/nlohmann_json)


set(JSON_BuildTests OFF CACHE INTERNAL "")