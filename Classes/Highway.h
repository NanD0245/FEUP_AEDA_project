//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_HIGHWAY_H
#define AEDA2020_PORTAGENS_HIGHWAY_H

#include "Toll.h"

class Highway {
    string name;
    vector<Toll *> tolls;
public:
    Highway(string name);
    string getName() const;
    void addToll(Toll * t1);
    bool removeToll(Toll * t1);
    bool operator==(const Highway &l2);
};


#endif //AEDA2020_PORTAGENS_HIGHWAY_H
