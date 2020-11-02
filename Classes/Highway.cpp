//
// Created by mim on 24/10/20.
//

#include "Highway.h"

using namespace std;

Highway::Highway(string name) : name(name) { tolls.clear(); }

string Highway::getInfo() const { return name; }

string Highway::getName() const {return name;}

void Highway::setName(const string new_name) { name = new_name; }


Toll * Highway::getToll(string name) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (name == tolls[i]->getName())
            return tolls[i];
    }
    return nullptr;
}

Toll * Highway::getTollIndex(int i) {
    if (i < getNumTolls())
        return tolls[i];
    return nullptr;
}

bool Highway::addToll(string name, string geolocal, float highway_kilometer,bool type) {
    if (!type) {
        Toll *t1 = new TollEntrance(name, geolocal, highway_kilometer);
        for (size_t i = 0; i < tolls.size(); i++) {
            if (tolls[i]->getInfo() == t1->getInfo()) {
                return false;
            }
        }
        tolls.push_back(t1);
    }
    else {
        Toll *t1 = new TollOut(name, geolocal, highway_kilometer);
        for (size_t i = 0; i < tolls.size(); i++) {
            if (tolls[i]->getInfo() == t1->getInfo()) {
                return false;
            }
        }
        tolls.push_back(t1);
    }
    return true;
}

bool Highway::removeToll(Toll *t1) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (*tolls[i] == *t1) {
            tolls.erase(tolls.begin()+i);
            return true;
        }
    }
    return false;
}

int Highway::getNumTolls() const {return tolls.size();}


bool Highway::operator==(const Highway &l2) { return name == l2.getName(); }