cmake_minimum_required(VERSION 3.0.0)
project(NotepadSh VERSION 0.1.0)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})


add_executable(NotepadSh
 cmd_parser.cpp
 command.cpp
 main.cpp
 MyApp.cpp
 MyFrame.cpp
)
include_directories("inc/")
target_link_libraries(NotepadSh ${wxWidgets_LIBRARIES})