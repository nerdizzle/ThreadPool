//
// Created by pygmalion on 13.11.19.
//

#ifndef THREADPOOL_LAMBDATASK_H
#define THREADPOOL_LAMBDATASK_H

#include <functional>
#include <thread>
#include "Task.h"
#include "ThreadPool.h"



class DummyTask : public Task {
private:
    std::string taskIdentifier;
public:
    DummyTask(std::string taskIdentifier="<DummyTask>") : taskIdentifier{taskIdentifier} { ; };
    ~DummyTask(){ ; };
    void operator()(const ThreadPool &threadPool, std::thread::id threadId) const override {
        std::cout << "ThreadPool works on Thread " << threadId << std::endl;
    }
};
#endif //THREADPOOL_LAMBDATASK_H
