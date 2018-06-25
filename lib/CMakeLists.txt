cmake_minimum_required(VERSION 3.9)
project(Hungarian)
set(CMAKE_CXX_STANDARD 17)
add_executable(hungarian main.cc hungarian.cc hungarian.h csv.cc csv.h)
