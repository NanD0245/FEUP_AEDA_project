//
// Created by mim on 24/10/20.
//

#include "Movement.h"

Movement::Movement(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date *date) : vehicle(vehicle1), highway(highway1), toll(toll1), lane(lane1), date(date) {
    type = false;
}

Date * Movement::getDate() const {return date;}

Highway * Movement::getHighway() const {return highway;}

Lane * Movement::getLane() const {return lane;}

Toll * Movement::getToll() const {return toll;}

Vehicle * Movement::getVehicle() const {return vehicle;}

bool Movement::getType() const {return type;}

string Movement::getInfo() const {
    return date->getInfo() + " - " + to_string(type) + " - " + highway->getInfo() + " - " + toll->getInfo() + " - " + lane->getInfo()+ " - " + vehicle->getInfo();
}

MovementEntry::MovementEntry(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date *date) : Movement(vehicle1,highway1,toll1,lane1, date) {
    type = false;
}

string MovementEntry::getInfo() const {
    return Movement::getInfo();
}

/*bool MovementEntry::operator==(const MovementEntry &m1) {
    if (m1.getType() == 1)
        return false;
    return (m1.getVehicle() == vehicle && m1.getLane() == lane && m1.getDate() == date);
}*/

MovementOut::MovementOut(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date * date,
                         MovementEntry *entry) : Movement(vehicle1,highway1,toll1,lane1, date), entry(entry) {
    type = true;
    this->distance = abs(toll1->getKilometer() - entry->getToll()->getKilometer());
    this->price = distance*vehicle1->getTax();
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
    return Movement::getInfo() + " - " + to_string(distance) + " - " + to_string(price) + " - " + entry->getInfo();
}