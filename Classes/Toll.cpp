#include "Toll.h"
#include <iostream>

using namespace std;

Toll::Toll(string name, string geolocal, float highway_kilometer,string type) : name(name), geolocal(geolocal), highway_kilometer(highway_kilometer) {
    lanes.clear();
    if (type == "entrance") {
        this->type = true; // 1
    }
    else if (type == "exit") {
        this->type = false; // 0
    }
}

bool Toll::getType() const {return type;}

string Toll::getName() const {return name;}

string Toll::getGeolocal() const {return geolocal;}

float Toll::getKilometer() const {return highway_kilometer;}

bool Toll::addLane(Lane* l1) {
    if (l1->getType() == type) {
        lanes.push_back(l1);
        return true;
    }
    return false;
}

bool Toll::removeLane(Lane *l1) {
    for (size_t i = 0; i < lanes.size(); i++) {
        if (*lanes[i] == *l1) {
            lanes.erase(lanes.begin() + i);
            return true;
        }
    }
    return false;
}

bool Toll::operator==(const Toll& l2) const {
    return name == l2.getName() && geolocal == l2.getGeolocal() && highway_kilometer == l2.getKilometer() && type == l2.getType();
}

