
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_executable(example example.cpp)
target_link_libraries(example
    ActiveClass
    ${Boost_LIBRARIES}
)


