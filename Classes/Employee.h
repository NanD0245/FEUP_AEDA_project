#ifndef AEDA2020_PORTAGENS_EMPLOYEE_H
#define AEDA2020_PORTAGENS_EMPLOYEE_H

#include <string>

using namespace std;

/**
 * The class Employee is a class that has basic information about each
 * and every worker
 *
 * Each Employee has a name and a code, which are used to identify them
 * 
 */
class Employee {

    /**
     * the name can't be an empty string and is different from every other Employee
     */
    string name;

    /**
     * code is a unique number that identifies each Employee
     */
    int code;
public:

    /**
     * @brief Constructor of Employee class
     * @param name is a string that will be the 'name' variable that belongs to the class
     * @param code is an integer that will be the 'code' variable that belongs to the class
     */
    Employee(string name, int code);

    /**
     * @return object's name
     */
    string getName() const;

    /**
     * @return object's code
     */
    int getCode() const;

    /**
     * @return string with the format: name + " - " + code
     */
    string getInfo();

    /**
     * @return string with the format: "Employee Name: " + name + " - " + "Employee Code: " +  code
     */
    string showEmployee();
 
    /**
     * @param new_name sets name (can't be an empty string nor equal to any other name)
     */
    void setName(const string new_name);
};


#endif //AEDA2020_PORTAGENS_EMPLOYEE_H
