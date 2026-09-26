cmake_minimum_required(VERSION 3.15)

project(student_simulator
    VERSION 1.0.0
    DESCRIPTION "Console student-life simulator for a hackathon"
    LANGUAGES CXX)

add_executable(student-simulator
    src/main.cpp
    src/player.cpp
    src/text_data.cpp
    src/color.cpp)

target_compile_features(student-simulator PRIVATE cxx_std_17)

# The game relies on the Windows console API (windows.h), so it is Windows-only.
if (MSVC)
    target_compile_options(student-simulator PRIVATE /utf-8 /W3)
endif()
