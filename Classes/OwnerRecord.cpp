//
// Created by mim on 15/12/20.
//

#include "OwnerRecord.h"

OwnerRecord::OwnerRecord() {owners.clear(); }

int OwnerRecord::getNumOwners() const {return owners.size(); }

bool OwnerRecord::addOwner(string name) {
    for (const auto & owner : owners)
        if (owner.getName() == name) return false;
    pair<unordered_set<Owner>::iterator, bool> a = owners.insert(Owner(name));
    if (get<1>(a))
        return true;
    return false;
}

