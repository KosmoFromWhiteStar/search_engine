cmake_minimum_required(VERSION 3.25.2)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)

set(incl_path "${CMAKE_SOURCE_DIR}/incl")
set(test_path "${CMAKE_SOURCE_DIR}/tests")
set(src_path "${CMAKE_SOURCE_DIR}/src")
set(test_path "${CMAKE_SOURCE_DIR}/tests")

#JSON lib
if(search_engine_USE_EXTERNAL_JSON)
  find_package(nlohmann_json 3.2.0 REQUIRED)
else()
  set(JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory("${CMAKE_SOURCE_DIR}/incl/nlohmann_json")
endif()
#JSON lib

add_subdirectory(tests)
add_subdirectory(src)

set(JSON_BuildTests OFF CACHE INTERNAL "")