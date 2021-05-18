cmake_minimum_required(VERSION 3.0.0)
project(NotepadSh VERSION 0.1.0)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})


add_executable(NotepadSh
 src/cmd_parser.cpp
 src/command.cpp
 src/main.cpp
 src/MyApp.cpp
 src/MyFrame.cpp
)
include_directories("src/include/")
target_link_libraries(NotepadSh ${wxWidgets_LIBRARIES})