//
// Created by pygmalion on 19.11.19.
//
#include <iostream>
#include "Thread.h"

Thread::Thread(){
    thread = std::thread([this]{
        std::cerr << "constructed thread: " << std::this_thread::get_id() << "\n";
        while(running){
            running.store(false);
        }
    });
}

Thread::~Thread(){
    thread.join();
    running.store(false);
}

void Thread::waitUntilDone() {
    while(worker.load()){std::this_thread::yield();}
}

void Thread::assignWorker(Worker* w){
    worker.store(w);
};
