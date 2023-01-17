#include <iostream>
#include "employee.h"

using namespace std;

void Employee::Report() {
    cout << "Employee Id: " << this->id << " Number of Completed Tasks: " << this->completedTaskNum << " Work Time: " << this->workTime << endl;
    cout << "Tasks Completed: ";
    for (int i = 0; i < this->completedTask.size(); i++)
        cout << this->completedTask[i] << " ";
    cout << endl;
}