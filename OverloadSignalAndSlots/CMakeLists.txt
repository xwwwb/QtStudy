cmake_minimum_required(VERSION 3.23)
project(OverloadSignalAndSlots)

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

add_executable(OverloadSignalAndSlots main.cpp widget.h widget.cpp MyPushButton.cpp MyPushButton.h)
target_link_libraries(OverloadSignalAndSlots
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

