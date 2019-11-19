//
// Created by pygmalion on 12.11.19.
//

#ifndef THREADPOOL_THREADPOOL_H
#define THREADPOOL_THREADPOOL_H

#include "Thread.h"

#include <vector>
#include <functional>
#include <iostream>
#include <thread>
#include <tbb/concurrent_queue.h>

//forward declarations
class Worker;
class Task;
class ThreadPool {

private:
    int numThreads;
    tbb::strict_ppl::concurrent_queue<Task* > taskQueue;
    std::vector<std::unique_ptr<Thread> > threads;
    std::vector<Worker* > workerQueue;
    uint64_t numTasks;
    tbb::spin_mutex numTasksMutex;
    //std::vector<shared_ptr<Task>>
public:
    explicit ThreadPool(int numThreads);
    ~ThreadPool();
    void start();
    bool runTaskCascade();
    Task* getNextTask();
    bool tasksAvailable();
    void addTask(Task* t);
    void taskFinished();
};
#endif //THREADPOOL_THREADPOOL_H
