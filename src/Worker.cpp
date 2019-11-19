//
// Created by pygmalion on 19.11.19.
//

#include "Worker.h"
#include "ThreadPool.h"

Worker::Worker(ThreadPool *tp) : tp(tp) { ; }
Worker::~Worker()=default;

void runTaskToCompletion(){
    Task* task;
    task = tp->getNextTask();
};
void assignThread (){};
void runTaskToCompletion();
Task* stealTask();
