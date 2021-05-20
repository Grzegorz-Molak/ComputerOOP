cmake_minimum_required(VERSION 3.5)

project(PROJEKT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE"${CMAKE_CXX_FLAGS_RELEASE}-D_REALESE")

add_executable(PROJEKT main.cpp electronic.cpp computermonitor.cpp hairdryer.cpp monitor.cpp user.cpp  app.cpp useful.cpp computermonitor.h hairdryer.h electronic.h monitor.h user.h app.h interface.h useful.h container.h node.h containerinterface.h)
