//
// Created by mim on 24/10/20.
//

#include "Employee.h"

/**
 * @brief Constructor of Employee class
 * @param name is a string that will be the 'name' variable that belongs to the class
 * @param code is an integer that will be the 'code' variable that belongs to the class
 */
Employee::Employee(string name, int code) : name(name), code(code) {}

string Employee::getName() const {return name;}

int Employee::getCode() const {return code;}

/**
 * @return string that has the name and the code of the current object
 */
string Employee::getInfo() { return name + " - " + to_string(code); }

string Employee::showEmployee() {
    return "Employee Name: " + name + " - " + "Employee Code: " +  to_string(code);
}

void Employee::setName(const string new_name) { name = new_name; }

//void Employee::setCode(const int new_code) { code = new_code; }




