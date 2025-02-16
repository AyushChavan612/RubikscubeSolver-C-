cmake_minimum_required(VERSION 3.10)
project(Godshand)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Godshand
    main.cpp
    models/3DArrayModel.cpp
    models/RubiksCube.cpp
)

target_include_directories(Godshand PRIVATE models)
