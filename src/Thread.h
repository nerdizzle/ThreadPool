//
// Created by pygmalion on 15.11.19.
//

#ifndef THREADPOOL_THREAD_H
#define THREADPOOL_THREAD_H

#include <thread>
#include <atomic>

class Worker;

class Thread {
private:
    std::thread thread;
    std::atomic<Worker* >  worker;
    std::atomic_bool running{true};

public:
    Thread();
    ~Thread();

    Thread(const Thread& other) = delete;
    Thread(Thread&& other) = default;

    Thread& operator=(const Thread& other) = delete;
    Thread& operator=(Thread&& other) = default;

    void waitUntilDone();
    void assignWorker(Worker* w);

};
#endif //THREADPOOL_THREAD_H
