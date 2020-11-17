//
// Created by mim on 24/10/20.
//

#include "Highways.h"

Highways::Highways() {highways.clear();}

Highway * Highways::getHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getName())
            return highways[i];
    }
    return nullptr;
}

int Highways::getNumHighways() const {return highways.size();}

vector<Highway *> Highways::getHighways() {return highways;}

Highway * Highways::getHighwayIndex(int i) {
    if (i < highways.size())
        return highways[i];
    return nullptr;
}

bool Highways::addHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getName())
            return false;
    }
    auto *a1 = new Highway(name);
    highways.push_back(a1);
    return true;
}

bool Highways::removeHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getName()) {
            highways.erase(highways.begin() + i);
            return true;
        }
    }
    return false;
}

bool Highways::removeHighway(int i) {
    if (i >= highways.size())
        return false;
    highways.erase(highways.begin()+i);
    return true;
}

bool Highways::checkHighwayName(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getName())
            return false;
    }
    return true;
}
