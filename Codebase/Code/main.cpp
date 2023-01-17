#include <iostream>
#include <time.h>
#include <fstream>
#include "company.h"
#include "employee.h"
#include "task.h"

using namespace std;

// Company company;

void hire(Company *myCompany, int number) {
    // cout << "How many employees do you want to hire?" << endl;
    // int number;
    // cin >> number;
    if (number > 0) {
        // company.Hire(number);
        myCompany->Hire(number);
    }
}

void fire(Company *myCompany, int id) {
    // cout << "Which employee do you want to fire?" << endl;
    // int id;
    // cin >> id;
    if (id > 0) {
        // company.Fire(id);
        myCompany->Fire(id);
    }
}

void createTask(Company *myCompany, int number) {
    // cout << "How many tasks do you want to create?" << endl;
    // int number;
    // cin >> number;
    if (number > 0) {
        // company.createTask(number);
        myCompany->createTask(number);
    }
}

// void work() {
//     while (company.tasks.size() != 0) {
//         Task task = company.tasks.back();
//         company.tasks.pop_back();

//         int minWorkload = INT_MAX;
//         int pos;

//         for (int i = 0; i < company.employees.size(); i++) {
//             Employee employee = company.employees[i];
//             if (employee.workTime < minWorkload) {
//                 pos = i;
//                 minWorkload = employee.workTime;
//             }
//         }

//         company.employees[pos].workTime += task.timeNeed;
//         company.employees[pos].completedTaskNum++;
//         company.employees[pos].completedTask.push_back(task.id);
//     }

//     cout << "Current tasks finished" << endl;
// }

void work(Company *myCompany) {
    while (myCompany->tasks.size() != 0) {
        Task task = myCompany->tasks.back();
        myCompany->tasks.pop_back();

        int minWorkload = INT_MAX;
        int pos;

        for (int i = 0; i < myCompany->employees.size(); i++) {
            Employee employee = myCompany->employees[i];
            if (employee.workTime < minWorkload) {
                pos = i;
                minWorkload = employee.workTime;
            }
        }

        // Orignal Code
        // myCompany->employees[pos].workTime += task.timeNeed;


        // Improve Performance
        myCompany->employees[pos].workTime = myCompany->employees[pos].workTime + task.timeNeed;


        myCompany->employees[pos].completedTaskNum++;
        myCompany->employees[pos].completedTask.push_back(task.id);
    }

    cout << "Current tasks finished" << endl;
}

void showWorkReport(Company *myCompany) {
    // for (int i = 0; i < company.employees.size(); i++) {
    //     company.employees[i].Report();
    // }
    for (int i = 0; i < myCompany->employees.size(); i++) {
        myCompany->employees[i].Report();
    }
}

void showCompanyInfo(Company *myCompany) {
    // company.Report();
    myCompany->Report();
}

extern "C" {
    void test() {
        Company *myCompany = new Company(0, 0, 1);

        hire(myCompany, 10);
        fire(myCompany, 5);
        createTask(myCompany, 1000);
        showCompanyInfo(myCompany);
        work(myCompany);
        showWorkReport(myCompany);

        delete myCompany;
    }
}

int main() {

    cout << "Operation Instruction" << endl;
    cout << "1. hire: hire employees for company" << endl;
    cout << "2. fire: fire a specific employee" << endl;
    cout << "3. task: create tasks for employees to complete" << endl;
    cout << "4. work: assign tasks to employees and make them work" << endl;
    cout << "5. report: show work report of each employee" << endl;
    cout << "6. company: show company information" << endl;
    cout << "7. stop: exit program" << endl;

    ofstream output("/Users/kehanzhang/Desktop/Workspace/Projects/lab-3-multithreading-Kehan-Zhang/Data/native.txt");
    for (int i = 0; i < 1000; i++) {
        clock_t start,end;
        start = clock();

        test();

        end = clock();
        output<<  (double)(end-start)/CLOCKS_PER_SEC << endl;
    }
    output.close();

    // while (true) {
    //     cout << "\nChoose operation: hire, fire, task, work, report, company, stop" << endl;

    //     string operation;
    //     cin >> operation;
        
    //     if (operation == "hire") {
    //         hire();
    //     } else if (operation == "fire") {
    //         fire();
    //     } else if (operation == "task") {
    //         createTask();
    //     } else if (operation == "work") {
    //         work();
    //     } else if (operation == "report") {
    //         showWorkReport();
    //     } else if (operation == "company") {
    //         showCompanyInfo();
    //     } else if (operation == "stop") {
    //         break;
    //     }

    // }

    return 0;
}