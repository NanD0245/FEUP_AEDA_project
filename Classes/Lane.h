#ifndef AEDA2020_PORTAGENS_LANE_H
#define AEDA2020_PORTAGENS_LANE_H

#include "Employee.h"
#include <string>

using namespace std;

class Lane {
protected:
    int lane_number;
    bool type;
    bool greenlane;
public:
    Lane(int lane_number, bool type, bool greenlane);
    int getLaneNumber() const;
    bool getType() const;
    bool getGreenLane() const;
    virtual string getInfo() const;
    bool operator==(const Lane &l2) const;
};

class LaneEmployee : public Lane {
    Employee* employee;
public:
    LaneEmployee(int lane_number, bool type, bool greenlane, Employee* e);
    void setEmployee(Employee* e);
    Employee * getEmployee() const;
    string getInfo() const;
    //void changeEmployee();
};


#endif //AEDA2020_PORTAGENS_LANE_H
