//
// Created by mim on 15/12/20.
//

#include "OwnerRecord.h"

OwnerRecord::OwnerRecord() {owners.clear(); }

int OwnerRecord::getNumOwners() const {return owners.size(); }

bool OwnerRecord::addOwner(string name, string email) {
    for (const auto & owner : owners)
        if (owner.getEmail() == email) return false;
    pair<unordered_set<Owner>::iterator, bool> a = owners.insert(Owner(name, email));
    if (get<1>(a))
        return true;
    return false;
}

bool OwnerRecord::deleteOwner(string email) {
    for (auto it = owners.begin(); it != owners.end(); it++)
        if (it->getEmail() == email) {
            owners.erase(it);
            return true;
        }
    return false;
}
