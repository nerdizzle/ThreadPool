#include <iostream>

#include "ThreadPool.h"
#include "DummyTask.h"

int main() {
    std::cout << " Thread Pool " << std::endl;
    std::cout << " ----------- " << std::endl;

    const int numThreads = 2;
    const int numTasks = 10;
    ThreadPool tp{numThreads};

    for(int i=0;i<numTasks; i++){
        auto t = std::make_shared<DummyTask >();
        tp.addTask(t.get());
    }

    return EXIT_SUCCESS;
}