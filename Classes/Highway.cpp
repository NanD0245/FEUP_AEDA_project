//
// Created by mim on 24/10/20.
//

#include "Highway.h"

using namespace std;

Highway::Highway(string name) : name(name) { tolls.clear(); }

string Highway::getInfo() const { return name; }

string Highway::getName() const {return name;}

void Highway::setName(const string new_name) { name = new_name; }

Toll * Highway::getToll(Toll *t1) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (t1->getInfo() == tolls[i]->getInfo())
            return tolls[i];
    }
    return nullptr;
}

bool Highway::addToll(Toll *t1) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (*tolls[i] == *t1) {
            return false;
        }
    }
    tolls.push_back(t1);
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

bool Highway::operator==(const Highway &l2) { return name == l2.getName(); }