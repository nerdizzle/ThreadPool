//
// Created by pygmalion on 19.11.19.
//

#include "Worker.h"
#include "Task.h"

Worker::Worker(ThreadPool *tp) : tp(tp) { ; }
Worker::~Worker() = default;

void Worker::runTaskToCompletion(){
    std::thread::id workerId = std::this_thread::get_id();
    while(true){
        Task* task = nullptr;
        task = tp->getNextTask();
        if(task == nullptr){
            if(tp->tasksAvailable()){
                std::this_thread::yield();
            }else{
                break;
            }
        } else {
            std::cout << "task could be fetched from worker" << workerId << std::endl;
            // execute Task, overwritten function operator
            (task)->operator()(*tp, workerId);
            tp->taskFinished();
        }
        //break;
    }
};
Task* stealTask();
