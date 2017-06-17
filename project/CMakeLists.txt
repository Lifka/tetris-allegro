cmake_minimum_required(VERSION 3.7)
project(project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Model/Piece.cpp Model/Piece.h Model/PieceType.cpp Model/Rotation.cpp)
add_executable(project ${SOURCE_FILES})