cmake_minimum_required(VERSION 3.21)
project(lab_02)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE PROJ_FILES
        src/*.cpp
        src/*.hpp
        src/*.h
        )

add_executable(lab_02 ${PROJ_FILES})

include_directories(src)
