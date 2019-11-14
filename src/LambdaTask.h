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
    using taskFunc_t = std::function<void(const ThreadPool&, std::thread::id)>;
private:
    std::string taskIdentifier;
    taskFunc_t func;
public:
    explicit LambdaTask(taskFunc_t func, std::string taskIdentifier="<LambdaTask>") : func{func}, taskIdentifier{taskIdentifier} {;};
    ~LambdaTask(){;};
    void operator()(const ThreadPool &threadPool, std::thread::id threadId) const {
        func(threadPool,threadId);
    }
};
#endif //THREADPOOL_LAMBDATASK_H
