//
// Created by mim on 24/10/20.
//

#include "Movements.h"

Movements::Movements() {movements.clear();}

bool Movements::addMovement(Movement *m1) {
    for(size_t i = 0; i < movements.size();i++) {
        if (movements[i]->getInfo() == m1->getInfo())
            return false;
    }
    movements.push_back(m1);
    return true;
}

Movement * Movements::getMovementIndex(int i) {
    return movements[i];
}