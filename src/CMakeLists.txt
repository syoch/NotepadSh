project(NotepadShBin VERSION 0.1.0)
add_executable(NotepadShBin
    main.cpp
    MyApp.cpp
    MyFrame.cpp
    command.cpp
    cmd_parser.cpp
)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

target_link_libraries(NotepadSh ${wxWidgets_LIBRARIES})

include(${wxWidgets_USE_FILE})
include_directories(../inc)