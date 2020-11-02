//
// Created by mim on 22/10/20.
//

#include "Employees.h"

using namespace std;

IdentNum Employees::code = 0;

Employees::Employees() {
    employees.clear();
}

int Employees::getNumEmployees() const {return employees.size();}

bool Employees::addEmployee(string name) {
    for (size_t i = 0; i < employees.size(); i++)
        if (employees[i]->getName() == name)
            return false;
    auto *e1 = new Employee(name, code);
    employees.push_back(e1);
    code++;
    return true;
}

bool Employees::removeEmployee(int code) {
    for (size_t i = 0; i < employees.size(); i++)
        if (code == employees[i]->getCode()) {
            employees.erase(employees.begin()+i);
            return true;
        }
    return false;
}

Employee * Employees::getEmployee(int code) {
    for (size_t i=0 ; i < employees.size(); i++) {
        if (employees[i]->getCode() == code)
            return employees[i];
    }
    return nullptr;
}

Employee * Employees::getEmployee(string name) {
    for (size_t i=0 ; i < employees.size(); i++) {
        if (employees[i]->getName() == name)
            return employees[i];
    }
    return nullptr;
}

Employee * Employees::getEmployeeIndex(int i) {
    if (i < employees.size())
        return employees[i];
    return nullptr;
}