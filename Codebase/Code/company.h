#ifndef COMPANY_H
#define COMPANY_H

#include <vector>

using namespace std;

class Employee;
class Task;

class Company {
    public:
        Company(int curEmployeeNum, int totalEmployeeNum, int taskId);
        ~Company() {};
        int curEmployeeNum;
        int totalEmployeeNum;
        int taskId;
        vector<Employee> employees;
        vector<Task> tasks;
        
        void Hire(int number);
        void Fire(int id);
        void createTask(int number);
        void Report();

};

#endif