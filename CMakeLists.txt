cmake_minimum_required(VERSION 3.0.0)
project(cy-project-template VERSION 0.1.0)

include_directories(include)

add_executable(cygenerate main.cpp)

add_subdirectory(src)

target_compile_features(cygenerate PRIVATE cxx_std_17)