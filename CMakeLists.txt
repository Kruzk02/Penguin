cmake_minimum_required(VERSION 4.2)
project(penguin)

find_package(SDL3 REQUIRED)

set(CMAKE_CXX_STANDARD 26)

add_executable(penguin main.cpp)

target_link_libraries(penguin SDL3::SDL3)
