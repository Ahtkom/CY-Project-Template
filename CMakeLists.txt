cmake_minimum_required(VERSION 3.0.0)
project(cy-project-template VERSION 0.1.0)


set(TARGET_NAME cygenerate)

add_executable(${TARGET_NAME} main.cpp)

add_subdirectory(include)
add_subdirectory(src)

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)