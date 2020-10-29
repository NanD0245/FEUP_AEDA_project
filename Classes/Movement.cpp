//
// Created by mim on 24/10/20.
//

#include "Movement.h"

Movement::Movement(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, string &date) : vehicle(vehicle1), highway(highway1), toll(toll1), lane(lane1), date(date) {
    type = false;
}

string Movement::getDate() const {return date;}

Highway * Movement::getHighway() const {return highway;}

Lane * Movement::getLane() const {return lane;}

Toll * Movement::getToll() const {return toll;}

Vehicle * Movement::getVehicle() const {return vehicle;}

bool Movement::getType() const {return type;}

string Movement::getInfo() const {
    return date + to_string(type);
}

MovementEntry::MovementEntry(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, string &date) : Movement(vehicle1,highway1,toll1,lane1, date) {
    type = false;
}

string MovementEntry::getInfo() const {
    return date + to_string(type);
}

/*bool MovementEntry::operator==(const MovementEntry &m1) {
    if (m1.getType() == 1)
        return false;
    return (m1.getVehicle() == vehicle && m1.getLane() == lane && m1.getDate() == date);
}*/

MovementOut::MovementOut(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, string &date,
                         MovementEntry *entry, float distance, float price) : Movement(vehicle1,highway1,toll1,lane1, date), entry(entry), distance(distance), price(price) {
    type = true;
}

float MovementOut::getDistance() const {return distance;}

MovementEntry * MovementOut::getEntry() const {return entry;}

float MovementOut::getPrice() const {return price;}

/*bool MovementOut::operator==(const MovementOut &m1) {
    if (m1.getType() == 0)
        return false;
    return (m1.getVehicle() == vehicle && m1.getLane() == lane && m1.getDate() == date && m1.getDistance() == distance && m1.getPrice() == price && m1.getEntry() == entry);
}*/

string MovementOut::getInfo() const {
    return date + to_string(type) + to_string(distance) + to_string(price);
}