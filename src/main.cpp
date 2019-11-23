#include <iostream>

#include "ThreadPool.h"
#include "DummyTask.h"

int main() {
    std::cout << "------------------- " << std::endl;
    std::cout << "    Thread Pool " << std::endl;
    std::cout << "------------------- " << std::endl;

    const int numThreads = 3;
    const int numTasks = 10;
    ThreadPool tp{numThreads};

    //initialize ThreadPool
    tp.start();

    // add tasks to the ThreadPool
    for(int i=0;i<numTasks; i++){
        auto t = std::make_shared<DummyTask >();
        tp.addTask(t.get());
    }

    // process tasks
    tp.runTaskCascade();
    // close ThreadPool

    return EXIT_SUCCESS;
}