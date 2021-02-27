cmake_minimum_required(VERSION 3.18)

project(pre-json LANGUAGES C CXX)

include(FetchContent)

set(BOOST_VERSION 1.72.0)
set(BOOST_COMPONENTS    
    fusion   
    regex 
)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.9.1

)

FetchContent_GetProperties(nlohmann_json)
if(NOT nlohmann_json_POPULATED)
  FetchContent_Populate(nlohmann_json)
  # add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR} EXCLUDE_FROM_ALL)
  SET(BUILD_TESTING OFF)
  add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR})
  
endif()


file(GLOB_RECURSE lib_pre_json_sources "./pre/*.cpp" "./pre/**/*.h"  "./pre/**/*.hpp" "./pre/**/*.cpp")

add_library(pre-json INTERFACE ${lib_pre_json_sources} )

target_include_directories ( pre-json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( pre-json INTERFACE nlohmann_json )
