//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_HIGHWAYS_H
#define AEDA2020_PORTAGENS_HIGHWAYS_H

#include "Highway.h"

class Highways {
    vector<Highway *> highways;
public:
    Highways();
    Highway * getHighway(Highway * l1);
    bool addHighway(Highway * l1);
    bool removeHighway(Highway * l1);
};


#endif //AEDA2020_PORTAGENS_HIGHWAYS_H
