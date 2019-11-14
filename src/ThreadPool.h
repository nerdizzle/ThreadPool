//
// Created by pygmalion on 12.11.19.
//

#ifndef THREADPOOL_THREADPOOL_H
#define THREADPOOL_THREADPOOL_H

#include <tbb/concurrent_queue.h>
#include "Task.h"

class ThreadPool {
private:
    int numThreads;
    tbb::strict_ppl::concurrent_queue<Task* > taskQueue;
    //std::vector<shared_ptr<Task>>
public:
    ThreadPool(int numThreads) : numThreads{numThreads} { ; };

    void addTask(Task* t){
        taskQueue.emplace(std::move(t));
    };
};
#endif //THREADPOOL_THREADPOOL_H
