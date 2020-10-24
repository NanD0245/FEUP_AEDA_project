//
// Created by mim on 22/10/20.
//

#ifndef AEDA2020_PORTAGENS_EMPLOYEES_H
#define AEDA2020_PORTAGENS_EMPLOYEES_H

#include <string>
#include <vector>

using namespace std;

class Employer;

class Employees {
protected:
    vector<Employer *> employees;
public:
    Employees() {};
};


#endif //AEDA2020_PORTAGENS_EMPLOYEES_H
