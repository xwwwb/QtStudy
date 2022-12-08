cmake_minimum_required(VERSION 3.23)
project(CommonComponents)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/xwwwb/Qt/6.2.4/macos")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CommonComponents main.cpp Widget.cpp Widget.h)
target_link_libraries(CommonComponents
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

