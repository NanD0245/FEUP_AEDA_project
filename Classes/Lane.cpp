//
// Created by mim on 24/10/20.
//

#include "Lane.h"
#include <iostream>

using namespace std;

Lane::Lane(int lane_number, bool type, bool greenlane) : lane_number(lane_number), type(type), greenlane(greenlane) {}

bool Lane::getType() const {return type;};

bool Lane::getGreenLane() const {return greenlane;};

int Lane::getLaneNumber() const {return lane_number;}

LaneEmployee::LaneEmployee(int lane_number, bool type, bool greenlane, Employee* e) : Lane(lane_number,type,greenlane), employee(e) {}

void LaneEmployee::setEmployee(Employee* e) {employee = e;}

Employee * LaneEmployee::getEmployee() const {return employee;}

bool Lane::operator==(const Lane &l2) const {
    return (lane_number == l2.getLaneNumber() && type == l2.getType() && greenlane == l2.getGreenLane());
}
