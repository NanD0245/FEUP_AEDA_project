//
// Created by mim on 22/10/20.
//

#include "Employees.h"

using namespace std;

Employees::Employees() {
    employees.clear();
}

bool Employees::addEmployee(string name) {
    for (size_t i = 0; i < employees.size(); i++)
        if (employees[i]->getName() == name)
            return false;
    auto *e1 = new Employee(name, code);
    employees.push_back(e1);
    code++;
    return true;
}

bool Employees::removeEmployee(Employee e1) {
    for (size_t i = 0; i < employees.size(); i++)
        if (e1.getInfo() == employees[i]->getInfo()) {
            employees.erase(employees.begin()+i);
            return true;
        }
    return false;
}