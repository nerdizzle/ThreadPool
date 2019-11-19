//
// Created by pygmalion on 15.11.19.
//

#ifndef THREADPOOL_WORKER_H
#define THREADPOOL_WORKER_H

#include <tbb/concurrent_queue.h>
#include "ThreadPool.h"
#include "Task.h"

//class Task;
//class ThreadPool;

class Worker {

private:
    tbb::strict_ppl::concurrent_queue<Task* > workerTaskQueue; // for task stealing
    ThreadPool* tp;
public:
    Worker(ThreadPool* tp) : tp(tp) { ; }
    ~Worker()=default;

    void runTaskToCompletion(){
        Task* task;
        task = tp->getNextTask();
    };
    void assignThread (){};
};
#endif //THREADPOOL_WORKER_H
