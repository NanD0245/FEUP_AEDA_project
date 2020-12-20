//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_INTERVENTIONRECORDS_H
#define AEDA2020_PORTAGENS_INTERVENTIONRECORDS_H

#include "Intervention.h"
#include "bst.h"

class InterventionRecord {
    BST<Intervention> interventions;
public:
    InterventionRecord();
    bool addIntervetion(Intervention i1);
    bool removeIntervention(Intervention i1);

};


#endif //AEDA2020_PORTAGENS_INTERNTIONRECORDS_H
