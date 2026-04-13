cmake_minimum_required(VERSION 4.2)
project(project)

set(CMAKE_CXX_STANDARD 26)

add_executable(project
        edge/edge.cpp
        fog/fog.cpp
        edge/edge.hpp
        fog/fog.hpp
        common/digital_human.cpp
        common/digital_human.hpp
        edge/main.cpp
        fog/main.cpp
)
