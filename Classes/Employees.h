//
// Created by mim on 22/10/20.
//

#ifndef AEDA2020_PORTAGENS_EMPLOYEES_H
#define AEDA2020_PORTAGENS_EMPLOYEES_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int IdentNum;

class Employees {
    vector<Employee *> employees;
    static IdentNum code;
public:
    Employees();
    int getNumEmployees() const;
    Employee * getEmployee(int code);
    Employee * getEmployee(string name);
    Employee * getEmployeeIndex(int i);
    bool addEmployee(string name);
    bool removeEmployee(int code);
};



#endif //AEDA2020_PORTAGENS_EMPLOYEES_H
