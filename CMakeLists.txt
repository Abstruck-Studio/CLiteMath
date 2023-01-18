cmake_minimum_required(VERSION 3.24)
project(CLiteMath)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLiteMath main.cpp number/Complex.h tool/Matrix.h CLiteMath.h)
