//
// Created by mim on 24/10/20.
//

#include "Employee.h"

Employee::Employee(string name, int code) : name(name), code(code) {}

string Employee::getName() const {return name;}

int Employee::getCode() const {return code;}

string Employee::getInfo() {
    return name + " - " + to_string(code);
}

