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
        fog/fogCallBack.cpp
        logger/reporter.cpp
        logger/reporter.hpp
        common/config.hpp
        common/migration_manager.hpp
        cloud/main.cpp
        fog/fog1/main.cpp
        fog/fog1/callback.cpp
        edge/home/main.cpp
        edge/work/main.cpp
        edge/mobile/main.cpp
        fog/fog2/callback.cpp
        fog/fog2/main.cpp
        common/migration_manager.cpp
        common/migration_manager.cpp
        common/migration_manager.cpp
        common/migration_manager.cpp
        edge/main.cpp
        fog/main.cpp
)
