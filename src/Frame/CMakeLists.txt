cmake_minimum_required(VERSION 3.1)
project(Frame)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Sources
add_library(Frame STATIC ./src/MyFrame.cpp)
target_include_directories(Frame INTERFACE ./include)
target_link_libraries(Frame ${wxWidgets_LIBRARIES})
