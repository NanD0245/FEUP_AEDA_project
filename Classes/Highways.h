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
    Highway * getHighway(string name);
    Highway * getHighwayIndex(int i);
    int getNumHighways() const;
    bool addHighway(string name);
    bool removeHighway(string name);
};


#endif //AEDA2020_PORTAGENS_HIGHWAYS_H
