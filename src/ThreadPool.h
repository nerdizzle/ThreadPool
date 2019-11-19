//
// Created by pygmalion on 12.11.19.
//

#ifndef THREADPOOL_THREADPOOL_H
#define THREADPOOL_THREADPOOL_H

#include <tbb/concurrent_queue.h>
#include <vector>
#include <mutex>

#include "Worker.h"
#include "Thread.h"
#include "Task.h"


//forward declarations
//class Worker;
//class Task;

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
    explicit ThreadPool(int numThreads) : numThreads{numThreads} {
        for(int i=0;i<numThreads;i++){
            threads.emplace_back(new Thread());
        }
    };

    void start(){
        // initialize numTasks with zero
        numTasks = 0;
        // assign worker to already created threads
        for(auto &thread: threads){
            auto w = new Worker(this);
            thread->assignWorker(w);
            workerQueue.emplace_back(w);
        }
    }

    bool runTaskCascade(){
        // let worker do their job
        for(auto& t: threads){
            std::cerr<<"Running Task Cascade"<< "\n";
            t->waitUntilDone();
        }

        // if threads are done, delete worker
        for(auto& w: workerQueue){
            delete(w);
        }
        workerQueue.clear();
        //
        std::cerr << taskQueue.unsafe_size()<< "\n";
        return !taskQueue.empty();
    }
    Task* getNextTask(){
        Task* task = nullptr;
        if(!taskQueue.try_pop(task)){
            std::cerr<<"could not get a task.."<< "\n";
            // keep thread spinning
            std::this_thread::yield();
        }

        if(task != nullptr){
            tbb::spin_mutex:: scoped_lock{numTasksMutex};
            numTasks++;
        }

        return task;
    }

    bool tasksAvailable(){
        return numTasks>0;
    }

    void addTask(Task* t){
        taskQueue.emplace(std::move(t));
    }

    void taskFinished(){
        tbb::spin_mutex:: scoped_lock{numTasksMutex};
        numTasks++;
    }
};
#endif //THREADPOOL_THREADPOOL_H
