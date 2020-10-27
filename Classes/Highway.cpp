//
// Created by mim on 24/10/20.
//

#include "Highway.h"

using namespace std;

Highway::Highway(string name) : name(name) {
    tolls.clear();
}

string Highway::getName() const {return name;}

void Highway::addToll(Toll *t1) {tolls.push_back(t1);}

bool Highway::removeToll(Toll *t1) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (*tolls[i] == *t1) {
            tolls.erase(tolls.begin()+i);
            return true;
        }
    }
    return false;
}

bool Highway::operator==(const Highway &l2) {
    return name == l2.getName();
}