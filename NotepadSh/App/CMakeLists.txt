cmake_minimum_required(VERSION 3.0.0)
project(NotepadSh VERSION 0.1.0)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Sources
add_library(App STATIC ./src/MyApp.cpp)
target_include_directories(App INTERFACE ./include)
target_link_libraries(App ${wxWidgets_LIBRARIES})