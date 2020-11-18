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

/**
 * Employees class is a class that aggregates different workers
 *
 * Each worker's information is stored in their corresponding Employee object,
 * which is then processed in the vector 'employees' that belongs to the Employees class using
 * the class's methods and functions.
 *
 * @param employees contains objects of Employee class that corresponds to workers
 * @param code
 */
class Employees {
    vector<Employee *> employees;
    static IdentNum code;
public:
    Employees();
    int getNumEmployees() const;
    Employee * getEmployee(int code);
    Employee * getEmployee(string name);
    Employee * getEmployeeIndex(int i);
    bool checkEmployeeName(string name);
    bool addEmployee(string name);
    bool addEmployee(Employee * e);
    bool removeEmployee(int i);
};



#endif //AEDA2020_PORTAGENS_EMPLOYEES_H
