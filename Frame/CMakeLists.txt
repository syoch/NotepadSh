cmake_minimum_required(VERSION 3.1)
project(frame LANGUAGES CXX)

# Wxwidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Files
add_library(frame STATIC src/MyFrame.cpp)
target_include_directories(frame INTERFACE ../include)
target_include_directories(frame INTERFACE .include)

# Features
target_compile_features(frame PRIVATE cxx_std_11)