cmake_minimum_required(VERSION 3.16)
project(raylib_example C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default to the raylib install produced by scripts/build-linux.sh
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../raylib-install")

find_package(raylib CONFIG REQUIRED)
add_subdirectory(../../rlImGui third_party/rlImGui)

add_executable(raylib_example src/main.cpp)
target_link_libraries(raylib_example PRIVATE raylib rlimgui)
