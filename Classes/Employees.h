//
// Created by mim on 22/10/20.
//

#ifndef AEDA2020_PORTAGENS_EMPLOYEES_H
#define AEDA2020_PORTAGENS_EMPLOYEES_H

#include "Employee.h"
#include <string>
#include <vector>

using namespace std;

static int code = 0;

class Employees {
    vector<Employee *> employees;
public:
    Employees();
    bool addEmployee(string name);
    bool removeEmployee(Employee e1);
};


#endif //AEDA2020_PORTAGENS_EMPLOYEES_H
