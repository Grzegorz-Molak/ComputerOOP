cmake_minimum_required(VERSION 3.5)

project(PROJEKT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DEBUG)

add_executable(PROJEKT main.cpp monitor.cpp model.cpp user.cpp model.h monitor.h user.h)
