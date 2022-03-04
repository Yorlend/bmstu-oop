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

add_executable(lab_01 main.cpp ui/main_window.cpp ui/main_window.hpp ui/main_window.ui core/operation_manager.cpp core/operation_manager.hpp core/operations/load.cpp core/operations/load.hpp core/operations/render.cpp core/operations/render.hpp core/operations/move.cpp core/operations/move.hpp core/operations/resize.cpp core/operations/resize.hpp core/operations/rotate.cpp core/operations/rotate.hpp core/utils/error_codes.hpp)
target_link_libraries(lab_01
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

