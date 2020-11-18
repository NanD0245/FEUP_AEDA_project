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
    bool checkHighwayName(string name);
    int getNumHighways() const;
    vector<Highway *> getHighways();
    bool addHighway(string name);
    void addHighway(Highway * h);
    bool removeHighway(string name);
    bool removeHighway(int i);
};


#endif //AEDA2020_PORTAGENS_HIGHWAYS_H
