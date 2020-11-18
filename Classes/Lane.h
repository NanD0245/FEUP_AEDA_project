#ifndef AEDA2020_PORTAGENS_LANE_H
#define AEDA2020_PORTAGENS_LANE_H

#include "Employee.h"
#include <string>

using namespace std;

class Lane {
protected:
    int lane_number;
    bool green_lane;
public:
    Lane(int lane_number, bool green_lane);
    int getLaneNumber() const;
    bool getGreenLane() const;
    virtual string getInfo() const;
    virtual string showLane() const;
    void setLaneNumber(int new_lane_number);
    //void setGreenLaneTrue();
    //void setGreenLaneFalse(Employee* e);
    virtual Employee * getEmployee() const {return nullptr;};
    virtual void setEmployee(Employee* e) {};
    bool operator==(const Lane &l2) const;
};

class LaneEmployee : public Lane {
    Employee* employee;
public:
    LaneEmployee(int lane_number, bool green_lane, Employee* e);
    void setEmployee(Employee* e);
    Employee * getEmployee() const;
    string getInfo() const;
    string showLane() const;
    //void changeEmployee();
};


#endif //AEDA2020_PORTAGENS_LANE_H
