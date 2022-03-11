cmake_minimum_required(VERSION 3.21)
project(lab_01)

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

add_executable(lab_01 ${PROJ_FILES}
        src/core/utils/projection/projection.hpp
        src/core/utils/projection/projection.cpp
        src/ui/Canvas.hpp
        src/ui/Canvas.cpp
        )

include_directories(src)

target_link_libraries(lab_01
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

