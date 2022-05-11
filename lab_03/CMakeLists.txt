cmake_minimum_required(VERSION 3.21)
project(lab_03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB_RECURSE PROJ_FILES
        src/*.cpp
        src/*.hpp
        )

add_executable(lab_03 ${PROJ_FILES})

include_directories(src)

target_link_libraries(lab_03
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )