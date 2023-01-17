#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <atomic>
#include "task.h"

using namespace std;

class Task;

class Employee {
    public:
        double workload = 0.0;
        atomic<bool> workStatus{false};

        void hire();
        void fire();
        void work(Task &task);
};

#endif