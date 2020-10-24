//
// Created by mim on 22/10/20.
//

#include "Employees.h"

using namespace std;

Employer::Employer(string name) : employer_name(name) {
    employees.push_back(this);
}