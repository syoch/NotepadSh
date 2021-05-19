cmake_minimum_required(VERSION 3.0.0)
project(NotepadSh VERSION 0.1.0)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# SubDirectories
add_subdirectory(Frame)

add_executable(NotepadSh
 main.cpp
 MyApp.cpp
)

target_include_directories(NotepadSh INTERFACE "./include/")
target_include_directories(NotepadSh INTERFACE "./Frame/include/")
target_link_libraries(NotepadSh ${wxWidgets_LIBRARIES})
target_link_libraries(NotepadSh Frame)