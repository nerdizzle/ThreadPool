//
// Created by pygmalion on 13.11.19.
//

#ifndef THREADPOOL_LAMBDATASK_H
#define THREADPOOL_LAMBDATASK_H

#include <functional>
#include <thread>
#include "Task.h"
#include "ThreadPool.h"



class LambdaTask : public Task {
private:
    std::string taskIdentifier;
public:
    explicit LambdaTask(taskFunc_t func, std::string taskIdentifier="<DummyTask>") : func{func}, taskIdentifier{taskIdentifier} {;};
    ~LambdaTask(){;};
    void operator()(const ThreadPool &threadPool, std::thread::id threadId) const  {
        std::cout << "ThreadPool works on Thread " + threadId  << std::endl;
    }
};
#endif //THREADPOOL_LAMBDATASK_H
