cmake_minimum_required(VERSION 3.0.0)
project(cy-project-template VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(TARGET_NAME cygen)

add_executable(${TARGET_NAME} main.cpp)

find_package(Boost 1.70 COMPONENTS program_options REQUIRED)
target_include_directories(${TARGET_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} ${Boost_LIBRARIES})

add_subdirectory(include)
add_subdirectory(src)