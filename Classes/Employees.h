#ifndef AEDA2020_PORTAGENS_EMPLOYEES_H
#define AEDA2020_PORTAGENS_EMPLOYEES_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * Employees class is a class that aggregates different workers.
 *
 * Each worker's information is stored in their corresponding Employee object,
 * which is then processed in the vector 'employees' using Employees' methods.
 *
 * @param employees contains all the different workers (objects from 'Employee' class)
 * @param code changes whenever a new worker('Employee') is added to the vector
 */
class Employees {
    vector<Employee *> employees;
    static int code;
public:
    /**
     * The constructor of Employees class initializes the 'employees' container as empty
     */
    Employees();

    /**
     * @return
     */
    int getNumEmployees() const;

    /**
     * Finds and provides Employee object according to its code
     * @param code is the code of Employee object to find
     * @return the Employee object that has the code 'code' if it exists, nullptr otherwise
     */
    Employee * getEmployee(int code);

    /**
     * Finds and provides Employee object according to its name
     * @param name is the name of Employee object to find
     * @return the Employee object that has the name 'name' if it exists, nullptr otherwise
     */
    Employee * getEmployee(string name);

    /**
     * Finds and provides Employee object according to its index
     * @param i is the index of the worker, in the vector 'employee'
     * @return the Employee object that has the code 'code' if it exists, nullptr otherwise
     */
    Employee * getEmployeeIndex(int i);

    /**
     * Checks if Employee with the name 'name' exists in the vector 'employees'
     * @param name
     * @return false if it already exists, true otherwise
     */
    bool checkEmployeeName(string name);

    /**
     * addEmployee function creates and adds a worker (that isn't already in the 'employees' container)
     * to the vector, with the correct name and code
     * @param name
     * @return true if it succeeded in adding a worker, false otherwise
     */
    bool addEmployee(string name);

    /**
     * addEmployee function adds a worker to the container 'employees'
     * @param e object of Employee class to add to vector 'employees'
     * @return true if it succeeded in adding a worker, false otherwise
     */
    bool addEmployee(Employee * e);

    /**
     * removeEmployee function removes a worker making use of his index in the
     * vector 'employee'
     * @param i is the index of the worker, in the vector 'employee',  to remove from the container
     * @return true if it succeeded in removing a worker, false otherwise
     */
    bool removeEmployee(int i);

    void setCode(int code);

    int getCode() const {return code;}
};



#endif //AEDA2020_PORTAGENS_EMPLOYEES_H
