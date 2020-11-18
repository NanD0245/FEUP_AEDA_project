//
// Created by mim on 22/10/20.
//

#include "Employees.h"

using namespace std;

IdentNum Employees::code = 0;

/**
 * The constructor of Employees class initializes the 'employees' container as empty
 */
Employees::Employees() {
    employees.clear();
}


int Employees::getNumEmployees() const {return employees.size();}

/**
 * addEmployee function creates and adds a worker (that isn't already in the 'employees' container)
 * to the vector, with the correct name and code
 * @param name
 * @return true if it succeeded in adding a worker, false otherwise
 */
bool Employees::addEmployee(string name) {
    for (size_t i = 0; i < employees.size(); i++)
        if (employees[i]->getName() == name)
            return false;
    auto *e1 = new Employee(name, code);
    employees.push_back(e1);
    code++;
    return true;
}

/**
 * removeEmployee function removes a worker making use of his index in the
 * vector 'employee'
 * @param i is the index of the worker, in the vector 'employee',  to remove from the container
 * @return true if it succeeded in removing a worker, false otherwise
 */
bool Employees::removeEmployee(int i) {
    if (i>=employees.size())
        return false;
    employees.erase(employees.begin()+i);
    return true;
}

/**
 * Finds and provides Employee object according to its code
 * @param code
 * @return the Employee object that has the code 'code' if it exists, nullptr otherwise
 */
Employee * Employees::getEmployee(int code) {
    for (size_t i=0 ; i < employees.size(); i++) {
        if (employees[i]->getCode() == code)
            return employees[i];
    }
    return nullptr;
}

/**
 * Finds and provides Employee object according to its name
 * @param name
 * @return the Employee object that has the name 'name' if it exists, nullptr otherwise
 */
Employee * Employees::getEmployee(string name) {
    for (size_t i=0 ; i < employees.size(); i++) {
        if (employees[i]->getName() == name)
            return employees[i];
    }
    return nullptr;
}

/**
 * Finds and provides Employee object according to its index
 * @param i is the index of the worker, in the vector 'employee'
 * @return the Employee object that has the code 'code' if it exists, nullptr otherwise
 */
Employee * Employees::getEmployeeIndex(int i) {
    if (i < employees.size())
        return employees[i];
    return nullptr;
}

/**
 * Checks if Employee with the name 'name' exists in the vector 'employees'
 * @param name
 * @return false if it already exists, true otherwise
 */
bool Employees::checkEmployeeName(string name) {
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i]->getName() == name)
            return false;
    }
    return true;
}