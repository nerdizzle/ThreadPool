cmake_minimum_required(VERSION 3.15)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -pthread")

find_package (THREADS REQUIRED pthread)
find_package(TBB REQUIRED tbb)

add_executable(ThreadPool src/main.cpp src/ThreadPool.h src/Task.h src/LambdaTask.h)
target_link_libraries(ThreadPool ${TBB_IMPORTED_TARGETS} Threads::Threads)
