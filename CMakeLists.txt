cmake_minimum_required(VERSION 3.25.2)
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
if(search_engine_USE_EXTERNAL_JSON)
  find_package(nlohmann_json 3.2.0 REQUIRED)
else()
  set(JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory("${CMAKE_SOURCE_DIR}/incl/nlohmann_json")
endif()

#JSON lib

add_subdirectory(src)

set(JSON_BuildTests OFF CACHE INTERNAL "")