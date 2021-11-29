cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(game)

include_directories(include SFML_INCLUDE_DIR)

link_directories(SFML_LIBRARY_DIR)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(game ${SOURCES}) 

set_target_properties(game PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

find_package(SFML COMPONENTS system window graphics network audio)

target_link_libraries (game sfml-graphics sfml-window sfml-system)