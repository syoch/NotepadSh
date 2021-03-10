cmake_minimum_required(VERSION 3.0.0)
project(NotepadSh VERSION 0.1.0)


add_executable(NotepadSh
    src/main.cpp
    src/MyApp.cpp
    src/MyFrame.cpp
    src/command.cpp
    src/cmd_parser.cpp
)
include_directories(inc)