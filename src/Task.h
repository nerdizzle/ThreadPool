//
// Created by pygmalion on 12.11.19.
//

#ifndef THREADPOOL_TASK_H
#define THREADPOOL_TASK_H

class Task {
public:
    Task(){};
    virtual ~Task(){};
    virtual void operator()(const ThreadPool &threadPool, std::thread::id threadId) const  = 0 ;

};

#endif //THREADPOOL_TASK_H
