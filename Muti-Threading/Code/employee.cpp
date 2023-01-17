#include <iostream>
#include "employee.h"
#include "task.h"

using namespace std;

void Employee::hire() {
    this->workStatus = true;
}

void Employee::fire() {
    this->workStatus = false;
}

void Employee::work(Task &task) {
    while (this->workStatus) {
        this->workload += 0.001;
        task.work();
    }
}