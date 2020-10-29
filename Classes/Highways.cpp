//
// Created by mim on 24/10/20.
//

#include "Highways.h"

Highways::Highways() {highways.clear();}

bool Highways::addHighway(Highway * l1) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (*(highways[i]) == *l1 )
            return false;
    }
    return true;
}

bool Highways::removeHighway(Highway * l1) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (*(highways[i]) == *l1) {
            highways.erase(highways.begin() + i);
            return true;
        }
    }
    return false;
}
