//
// Created by pygmalion on 15.11.19.
//

#ifndef THREADPOOL_THREAD_H
#define THREADPOOL_THREAD_H

#include "Worker.h"

#include <thread>
#include <atomic>


class Thread {
private:
    std::thread thread;
    std::atomic<Worker* >  worker;
    std::atomic_bool running{true};

public:
    Thread(){
        thread = std::thread([this]{
            std::cerr << "constructed thread: " << std::this_thread::get_id() << "\n";

            while(running){
                running.store(false);
            }


        });
    }
    ~Thread(){
        thread.join();
        running.store(false);
    }

    Thread(const Thread& other) = delete;
    Thread(Thread&& other) = default;

    Thread& operator=(const Thread& other) = delete;
    Thread& operator=(Thread&& other) = default;


    void waitUntilDone() {
        while(worker.load()){std::this_thread::yield();}
    }

    void assignWorker(Worker* w){
        worker.store(w);
    };

};
#endif //THREADPOOL_THREAD_H
