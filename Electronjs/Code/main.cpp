#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <unistd.h> 
#include <assert.h>

#include "employee.h"
#include "company.h"
#include "task.h"

using namespace std;

void hire(Company *myCompany) {
    myCompany->hire();
}

void startWork(Company *myCompany, Task *task) {
    myCompany->startWork(*task);
}

void stopWork(Company *myCompany) {
    myCompany->stopWork();
}

void fire(Company *myCompany) {
    myCompany->fire();
}

void report(Company *myCompany) {
    myCompany->report();
}

void test() {
    Company *myCompany = new Company(0);
    myCompany->employeeNum = thread::hardware_concurrency() - 1;
    // myCompany->employeeNum = 1;
    Task *task = new Task(0.0);  

    hire(myCompany);
    startWork(myCompany, task);
    while (true) {
        if (task->totalWork >= 10000) {
            stopWork(myCompany);
            break;
        }
    }
    
    report(myCompany);
    cout << "Company total workload: " << task->totalWork << endl;
    fire(myCompany);
    cout << endl;

    delete myCompany;
    delete task;
}

int main() {

    vector<double> time;
    
    for (int i = 1; i <= 10; i++) {
        cout << "Test " << i  << ":\n";
        clock_t start,end;
        start = clock();

        test();

        end = clock();
        time.push_back((double)(end - start) / CLOCKS_PER_SEC);
    }


    cout << "Time Analysis\n";
    for (int i = 0; i < time.size(); i++) {
        cout << i + 1 << " : "<<time[i] << endl;
    }

    return 0;
}