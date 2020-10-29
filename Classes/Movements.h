//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_MOVEMENTS_H
#define AEDA2020_PORTAGENS_MOVEMENTS_H

#include "Movement.h"
#include <vector>

using namespace std;

class Movements {
    vector<Movement *> movements;
public:
    Movements();
    bool addMovement(Movement* m1);
};


#endif //AEDA2020_PORTAGENS_MOVEMENTS_H
