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
        int v = 0;
        for (char i: o1.getName())
            v = 37*v + i;
        return v;
    }

    bool operator() (const Owner& o1, const Owner& o2) const
    {
        return o1.getName() == o2.getName();
    }
};

class OwnerRecord {
    unordered_set<Owner,ownerHash,ownerHash> owners;
public:
    OwnerRecord();
    bool addOwner(string name);
    bool deleteOwner(Owner o1);
    Owner getOwner(int index);
    int getNumOwners() const;
    vector<string> showOwners();
    bool addVehicleOwner(string name, Vehicle* vehicle);
    bool checkPlate(string plate);
    unordered_set<Owner,ownerHash,ownerHash> getOwners() const;
};


#endif //AEDA2020_PORTAGENS_ONWERS_H
