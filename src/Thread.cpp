//
// Created by pygmalion on 19.11.19.
//
#include <iostream>
#include "Thread.h"
#include "Worker.h"

Thread::Thread(){
    thread = std::thread([this]{
        std::cerr << "constructed thread: " << std::this_thread::get_id() << "\n";
        while(running){
            // fetch a worker
            while(!worker.load()){std::this_thread::yield();}
            std::cout << "worker has been fetched" << std::endl;
            worker.load()->runTaskToCompletion();
            std::cout << "task run to completion" << std::endl;
            // let worker do his job
            worker.store(nullptr);
            break;
        }
    });
}

Thread::~Thread(){
    std::cerr << "destructed thread: " << this->thread.get_id() << "\n";
    thread.join();
    running.store(false);
}

void Thread::waitUntilDone() {
    while(worker.load()){std::this_thread::yield();}
}

void Thread::assignWorker(Worker* w){
    worker.store(w);
};
