cmake_minimum_required(VERSION 3.15)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 17)

add_executable(ThreadPool src/main.cpp src/ThreadPool.h)