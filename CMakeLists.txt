cmake_minimum_required(VERSION 3.23)
project(Dots_and_Boxes)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES Box.cpp Box.h DotsAndBoxesGame.cpp DotsAndBoxesGame.h cmake-build-debug/termcolor.hpp Edge.cpp Edge.h main.cpp)

add_executable(Dots_and_Boxes Box.cpp Box.h DotsAndBoxesGame.cpp DotsAndBoxesGame.h cmake-build-debug/termcolor.hpp Edge.cpp Edge.h main.cpp savedGame.cpp)
