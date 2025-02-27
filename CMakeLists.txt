cmake_minimum_required(VERSION 2.8)

include_directories(include gtest)

# BUILD
add_subdirectory(sample)
add_subdirectory(tests)
add_subdirectory(gtest)