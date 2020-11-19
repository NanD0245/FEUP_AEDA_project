#include "Employees.h"

using namespace std;

int Employees::code = 0;

Employees::Employees() {
    employees.clear();
}

int Employees::getCode() const {return code;}

void Employees::setCode(int code) {this->code = code;}

int Employees::getNumEmployees() const {return employees.size();}

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

bool Employees::checkEmployeeName(string name) {
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i]->getName() == name)
            return false;
    }
    return true;
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

bool Employees::addEmployee(Employee * e){
    for (size_t i = 0; i < employees.size(); i++)
        if (employees[i]->getName() == e->getName())
            return false;
    employees.push_back(e);
    return true;
}

bool Employees::removeEmployee(int i) {
    if (i>=employees.size())
        return false;
    employees.erase(employees.begin()+i);
    return true;
}
