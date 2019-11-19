cmake_minimum_required(VERSION 3.15)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 20)

find_package (THREADS REQUIRED pthread)
find_package(TBB REQUIRED tbb)

add_executable(ThreadPool src/main.cpp src/ThreadPool.h src/Task.h src/LambdaTask.h src/DummyTask.h src/Thread.h src/Worker.h src/Worker.cpp)
target_link_libraries(ThreadPool ${TBB_IMPORTED_TARGETS} Threads::Threads)
