//
// Created by mim on 22/10/20.
//

#include "Employees.h"

using namespace std;

Employees::Employees() {
    employees.clear();
    code = 0;
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
    cout << "Employee not found" << endl;
    return nullptr;
}