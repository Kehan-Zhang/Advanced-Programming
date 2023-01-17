#include <iostream>
#include "company.h"
#include "employee.h"
#include "task.h"

using namespace std;

Company::Company(int curEmployeeNum, int totalEmployeeNum, int taskId) {
    this->curEmployeeNum = curEmployeeNum;
    this->totalEmployeeNum = totalEmployeeNum;
    this->taskId = taskId;
}

void Company::Hire(int number) {
    int curId = totalEmployeeNum + 1;
    for (int i = 1; i <= number; i++) {
        Employee employee;
        employee.id = curId;
        curId++;
        this->employees.push_back(employee);
    }

    this->totalEmployeeNum += number;
    this->curEmployeeNum += number; 

    cout << number << " employees hired" << endl;   
}

void Company::Fire(int id) {
    for (int i = 0; i < this->employees.size(); i++) {
        if (this->employees[i].id == id) {
            this->employees.erase(this->employees.begin() + i);
            this->curEmployeeNum--;
            cout << "Employee fired, id : " << id << endl;
            return;
        } 
    }

    cout << "Employee not found" << endl;
}

void Company::createTask(int number) {
    for (int i = 0; i < number; i++) {
        Task task;
        task.id = this->taskId;
        this->taskId++;
        task.timeNeed = 1 + (rand() % 100);
        this->tasks.push_back(task);
    }

    cout << number << " tasks created" << endl;
}

void Company::Report() {
    cout << "Total Employee Number: " << this->totalEmployeeNum 
         << "  Current Employee Number: " << this->curEmployeeNum
         << "  Remaining Tasks: " << this->tasks.size() << endl;
    cout << "Current Employees: ";
    for (int i = 0; i < this->employees.size(); i++) {
        cout << this->employees[i].id << " ";
    }
    cout << endl;
}
