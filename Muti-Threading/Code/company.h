#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <atomic>
#include <thread>
#include "task.h"

using namespace std;

class Employee;
class Task;

class Company {
    public:

        vector<Employee *> employee;
        vector<thread> threads;
        int employeeNum;

        Company(int employeeNum);
        ~Company() {};
        
        void hire();
        void startWork(Task &task);
        void stopWork();
        void fire();
        void report();

};

#endif