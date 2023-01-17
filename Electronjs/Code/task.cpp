#include <iostream>
#include "task.h"

using namespace std;

Task::Task(double totalWork) {
    this->totalWork = totalWork;
}

void Task::work() {
    this->mu.lock();
    this->totalWork += 0.001;
    this->mu.unlock();
}