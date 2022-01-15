cmake_minimum_required(VERSION 3.20)
project(HEIGVD_PRG1_ROBOT)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS="-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(HEIGVD_PRG1_ROBOT main.cpp Robot.cpp Robot.h Survivor.cpp Survivor.h
                                 annexe.cpp annexe.h saisie.cpp saisie.h)
