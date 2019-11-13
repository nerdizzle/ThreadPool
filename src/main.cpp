#include <iostream>

#include "ThreadPool.h"

int main() {
    std::cout << " Thread Pool " << std::endl;
    std::cout << " ----------- " << std::endl;

    const int numThreads = 2;
    ThreadPool tp{numThreads};

    return EXIT_SUCCESS;
}