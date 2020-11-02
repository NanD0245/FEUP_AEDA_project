#include "Toll.h"
#include <iostream>

using namespace std;

Toll::Toll(string name, string geolocal, float highway_kilometer, bool type) : name(name), geolocal(geolocal), highway_kilometer(highway_kilometer),type(type) {
    lanes.clear();
    /*if (type == "entrance") {
        this->type = false; // 0
    }
    else if (type == "exit") {
        this->type = true; // 1
    }*/
}

bool Toll::getType() const {return type;}

string Toll::getName() const {return name;}

string Toll::getGeolocal() const {return geolocal;}

float Toll::getKilometer() const {return highway_kilometer;}

string Toll::getInfo() const {
    return name + " - " + geolocal + " - " + to_string(highway_kilometer) + " - " + to_string(type);
}

/*Lane * Toll::getLane(int i) {
    if (i < lanes.size())
        return lanes[i];
    return nullptr;
}*/

int Toll::getNumLanes() const {return lanes.size();}

Lane * Toll::getLane(int i) {
    if (i < lanes.size())
        return lanes[i];
    return nullptr;
}

bool Toll::removeLane(int i) {
    bool check = false;
    if (i < lanes.size()) {
        lanes.erase(lanes.begin() + i);
        check= true;
    }
    if (!check)
        return false;
    for (size_t i = 0; i < lanes.size(); i++) {
        lanes[i]->setLaneNumber(i);
    }
    return true;
}

bool Toll::operator==(const Toll& l2) const {
    return name == l2.getName() && geolocal == l2.getGeolocal() && highway_kilometer == l2.getKilometer() && type == l2.getType();
}

TollEntrance::TollEntrance(string name, string geolocal, float highway_kilometer) : Toll(name,geolocal,highway_kilometer,false) {}

void TollEntrance::addLane() {
    int n_lane = lanes.size() + 1;
    auto *l1 = new Lane(n_lane, false);
    lanes.push_back(l1);
}

TollOut::TollOut(string name, string geolocal, float highway_kilometer) : Toll(name,geolocal,highway_kilometer,true) {}

void TollOut::addLane() {
    int n_lane = lanes.size() + 1;
    auto *l1 = new Lane(n_lane, true);
    lanes.push_back(l1);
}

void TollOut::addLane(Employee *e) {
    int n_lane = lanes.size() + 1;
    auto *l1 = new LaneEmployee(n_lane, false, e);
    lanes.push_back(l1);
}

