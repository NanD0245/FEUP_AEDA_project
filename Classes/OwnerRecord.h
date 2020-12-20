//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_ONWERS_H
#define AEDA2020_PORTAGENS_ONWERS_H

#include <unordered_set>
#include "Vehicle.h"
#include "Owner.h"

struct ownerHash
{
    int operator() (const Owner& o1) const
    {
        return 0;
    }

    bool operator() (const Owner& o1, const Owner& o2) const
    {
        return false;
    }
};

class OwnerRecord {
    unordered_set<Owner,ownerHash,ownerHash> owners;
public:
    OwnerRecord();
    bool addOwner(Owner o1);
};


#endif //AEDA2020_PORTAGENS_ONWERS_H
