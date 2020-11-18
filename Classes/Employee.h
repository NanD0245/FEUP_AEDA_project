//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_EMPLOYEE_H
#define AEDA2020_PORTAGENS_EMPLOYEE_H

#include <string>

using namespace std;


class Employee {
    string name;
    int code;
public:
    Employee(string name, int code);
    string getName() const;
    int getCode() const;
    string getInfo();
    string showEmployee();
    void setName(const string new_name);
    //void setCode(const int new_code);
};


#endif //AEDA2020_PORTAGENS_EMPLOYEE_H
