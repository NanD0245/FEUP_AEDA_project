#include "Movements.h"

Movements::Movements() {movements.clear();}

int Movements::getNumMovements() const {return movements.size();}

Movement * Movements::getMovementIndex(int i) {
    return movements[i];
}

vector<Movement *> Movements::getMovements() {return movements;}

bool Movements::addMovement(Movement *m1) {
    for(size_t i = 0; i < movements.size();i++) {
        if (movements[i]->getInfo() == m1->getInfo())
            return false;
    }
    movements.push_back(m1);
    return true;
}