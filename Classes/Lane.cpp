//
// Created by mim on 24/10/20.
//

#include "Lane.h"
#include <iostream>

using namespace std;

Lane::Lane(int lane_number, bool green_lane) : lane_number(lane_number), green_lane(green_lane) {}

Lane::Lane(){
    lane_number=0;
    green_lane=false;
}

int Lane::getLaneNumber() const {return lane_number;}

bool Lane::getGreenLane() const {return green_lane;};

string Lane::getInfo() const {
    return to_string(lane_number) + " - " + to_string(green_lane);
}

void Lane::setLaneNumber(const int new_lane_number) { lane_number = new_lane_number; }

LaneEmployee::LaneEmployee(int lane_number, bool greenlane, Employee* e) : Lane(lane_number,greenlane), employee(e) {}

void LaneEmployee::setEmployee(Employee* e) {employee = e;}

Employee * LaneEmployee::getEmployee() const {return employee;}

string LaneEmployee::getInfo() const {
    return Lane::getInfo() + " - " + employee->getInfo();
}

bool Lane::operator==(const Lane &l2) const {
    return (lane_number == l2.getLaneNumber() && green_lane == l2.getGreenLane());
}
