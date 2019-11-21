//
// Created by pygmalion on 19.11.19.
//

#include "ThreadPool.h"
#include "Thread.h"
#include "Task.h"
#include "Worker.h"

ThreadPool::ThreadPool(int numThreads) : numThreads{numThreads}{
    for(int i=0;i<numThreads;i++){
        threads.emplace_back(new Thread());
    }
};

ThreadPool::~ThreadPool(){};

void ThreadPool::start(){
    // initialize numTasks with zero
    numTasks = 0;
    // assign worker to already created threads
    for(auto &thread: threads){
        auto w = new Worker(this);
        thread->assignWorker(w);
        workerQueue.emplace_back(w);
    }
}

bool ThreadPool::runTaskCascade(){
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
Task* ThreadPool::getNextTask(){
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

bool ThreadPool::tasksAvailable(){
    return numTasks>0;
}

void ThreadPool::addTask(Task* t){
    taskQueue.emplace(std::move(t));
}

void ThreadPool::taskFinished(){
    tbb::spin_mutex:: scoped_lock{numTasksMutex};
    //std::cout << numTasks << std::endl;
    numTasks--;
}

