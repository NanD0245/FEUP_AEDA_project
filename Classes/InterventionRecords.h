//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_INTERVENTIONRECORDS_H
#define AEDA2020_PORTAGENS_INTERVENTIONRECORDS_H

#include "intervention.h"
#include "bst.h"

class InterventionRecords {
    BST<Intervention> bst;
public:
    bool add(Intervention i1);
    bool remove(Intervention i1);
    Intervention getIntervention();
    
};


#endif //AEDA2020_PORTAGENS_INTERNTIONRECORDS_H
