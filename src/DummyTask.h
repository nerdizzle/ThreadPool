//
// Created by pygmalion on 13.11.19.
//

#ifndef THREADPOOL_DUMMYTASK_H
#define THREADPOOL_DUMMYTASK_H

#include <functional>
#include <thread>
#include "Task.h"
#include "ThreadPool.h"



class DummyTask : public Task {
private:
    std::string taskIdentifier;
public:
    explicit DummyTask(std::string taskIdentifier="<DummyTask>") : taskIdentifier{taskIdentifier} {
        std::cout << taskIdentifier << std::endl;
    };
    ~DummyTask(){ ; };
    void operator()(const ThreadPool &threadPool, std::thread::id threadId) const override {
        std::cout << "ThreadPool works " << threadId << std::endl;
    }
};
#endif //THREADPOOL_DUMMYTASK_H
