#include <iostream>
#include "company.h"
#include "employee.h"

using namespace std;

Company::Company(int employeeNum) {
    this->employeeNum = employeeNum;
}

void Company::hire() {
    for (int i = 0; i < this->employeeNum; i++) {
        this->employee.push_back(new Employee());
    }

    cout << employeeNum << " employees hired" << endl;
}

void Company::startWork(Task &task) {
    if (this->employee.size() == 0)
        this->hire();

    for (int i = 0; i < this->employeeNum; i++) {
        this->employee[i]->workStatus = true;
        this->threads.push_back(thread(&Employee::work, this->employee[i], ref(task)));
    }

    cout << employeeNum << " employees start working" << endl;
}

void Company::stopWork() {
    for (int i = 0; i < employeeNum; i++) {
        this->employee[i]->workStatus = false;
    }

    // vector<thread>::iterator it;
    // for (it = this->threads.end(); it >= this->threads.begin(); it--) {
    //     if (it->joinable()) {
    //         it->join();
    //         this->threads.erase(it);
    //     }
    // }

    for (int i = 0; i < employeeNum; i++) {
        threads[i].join();
    }
    threads.clear();
        

    cout << employeeNum << " employees stop working" << endl;
}

void Company::fire() {
    if (this->threads.size() > 0)
        this->stopWork();

    for (int i = this->employee.size() - 1; i >= 0; i--) {
        this->employee[i]->fire();
        delete this->employee[i];
    }

    this->employee.clear();

    cout << employeeNum << " employees fired" << endl;
}

void Company::report() {
    for (int i = 0; i < this->employee.size(); i++) {
        cout << "Employee ID: " << i << "   Workload: " << this->employee[i]->workload << endl;
    }
}
