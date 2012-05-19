cmake_minimum_required(VERSION 2.6)
project(ActiveClass CXX)

find_package(Boost 1.36.0 REQUIRED COMPONENTS thread system)

include_directories(
    ${Boost_INCLUDE_DIRS}
)

add_subdirectory(src)
add_subdirectory(examples)

