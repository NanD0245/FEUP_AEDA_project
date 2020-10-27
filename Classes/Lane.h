//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_LANE_H
#define AEDA2020_PORTAGENS_LANE_H
#include "Employee.h"

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
    bool operator==(const Lane &l2) const;
};

/*class LaneEntrance : public Lane {

};

class LaneOut : public Lane {

};

class LaneGreen : public LaneOut {

};*/

class LaneEmployee : public Lane {
    Employee* employee;
public:
    LaneEmployee(int lane_number, bool type, bool greenlane, Employee* e);
    void setEmployee(Employee* e);
    Employee * getEmployee() const;
    //void changeEmployee();
};


#endif //AEDA2020_PORTAGENS_LANE_H
