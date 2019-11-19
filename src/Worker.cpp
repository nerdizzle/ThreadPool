//
// Created by pygmalion on 19.11.19.
//

#include "Worker.h"
#include "Task.h"

Worker::Worker(ThreadPool *tp) : tp(tp) { ; }
Worker::~Worker() = default;

void Worker::runTaskToCompletion(){
    Task* task;
    task = tp->getNextTask();
};
void Worker::assignThread (){};
Task* stealTask();
