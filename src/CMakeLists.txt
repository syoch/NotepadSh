cmake_minimum_required(VERSION 3.0.0)
project(NotepadSh VERSION 0.1.0)

# SubDirectories
add_subdirectory(Frame)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
message(${wxWidgets_USE_FILE})
include(${wxWidgets_USE_FILE})


add_executable(NotepadSh
 main.cpp
 MyApp.cpp
)
include_directories("./include/")
target_link_libraries(NotepadSh ${wxWidgets_LIBRARIES})
target_link_libraries(NotepadSh ${frame_LIBRARIES})