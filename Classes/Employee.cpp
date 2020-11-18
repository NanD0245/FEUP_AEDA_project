//
// Created by mim on 24/10/20.
//

#include "Employee.h"

Employee::Employee(string name, int code) : name(name), code(code) {}

string Employee::getName() const {return name;}

int Employee::getCode() const {return code;}

string Employee::getInfo() { return name + " - " + to_string(code); }

string Employee::showEmployee() {
    return "Employee Name: " + name + " - " + "Employee Code: " +  to_string(code);
}

void Employee::setName(const string new_name) { name = new_name; }

//void Employee::setCode(const int new_code) { code = new_code; }




