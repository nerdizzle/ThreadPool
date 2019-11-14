//
// Created by pygmalion on 12.11.19.
//

#ifndef THREADPOOL_TASK_H
#define THREADPOOL_TASK_H

class Task {
public:
    virtual ~Task(){};
    virtual void operator()() const {} ;

};

#endif //THREADPOOL_TASK_H
