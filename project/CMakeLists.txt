#Lifka --
cmake_minimum_required(VERSION 3.7)
project(project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Model/Piece.cpp Model/Piece.h Model/PieceType.h
        Model/Rotation.h Model/Point2D.cpp Model/Point2D.h Model/FactoryMethod.h Model/Factory.cpp Model/Factory.h Model/Board.cpp Model/Board.h Model/Options.cpp Model/Options.h)
add_executable(project ${SOURCE_FILES})