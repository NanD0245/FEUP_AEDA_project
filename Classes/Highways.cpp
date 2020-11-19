#include "Highways.h"

Highways::Highways() {highways.clear();}

int Highways::getNumHighways() const {return highways.size();}

Highway * Highways::getHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return highways[i];
    }
    return nullptr;
}

Highway * Highways::getHighwayIndex(int i) {
    if (i < highways.size())
        return highways[i];
    return nullptr;
}

vector<Highway *> Highways::getHighways() {return highways;}

bool Highways::checkHighwayName(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return true;
    }
    return false;
}

bool Highways::addHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return false;
    }
    auto *a1 = new Highway(name);
    highways.push_back(a1);
    return true;
}

void Highways::addHighway(Highway * h){
    highways.push_back(h);
}

bool Highways::removeHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo()) {
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
