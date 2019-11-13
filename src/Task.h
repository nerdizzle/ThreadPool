//
// Created by pygmalion on 12.11.19.
//

#ifndef THREADPOOL_TASK_H
#define THREADPOOL_TASK_H

class Task {
private:
    std::string taskIdentifier;

public:
    Task(std::string taskIdentifier) : taskIdentifier{taskIdentifier}{ ; };
    virtual ~Task(){};

    virtual void operator()();

};

#endif //THREADPOOL_TASK_H
