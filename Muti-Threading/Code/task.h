#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <functional>
#include <thread>

using namespace std;

class Task {
    public: 
        double totalWork;
        mutex mu;

        Task (double totalWork);
        ~Task() {};

        void work();
};

#endif