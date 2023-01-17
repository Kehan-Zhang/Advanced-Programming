#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>

using namespace std;

class Employee {
    public:
        int id;
        int completedTaskNum = 0;
        int workTime = 0;
        vector<int> completedTask;

        void Report();
};

#endif