cmake_minimum_required(VERSION 3.29.2)
project(penguin)

find_package(SDL3 REQUIRED)

set(CMAKE_CXX_STANDARD 26)

link_directories(include)

file(GLOB_RECURSE APP_SRC CONFIGURE_DEPENDS src/*.cpp)

add_executable(penguin ${APP_SRC}
)
target_include_directories(penguin
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(penguin SDL3::SDL3)
