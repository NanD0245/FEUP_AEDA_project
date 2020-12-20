//
// Created by mim on 15/12/20.
//

#include "InterventionRecord.h"

InterventionRecord::InterventionRecord() : interventions(Intervention("", nullptr, nullptr, nullptr, nullptr,0)) {}

bool InterventionRecord::addIntervetion(Intervention i1) {
    return interventions.insert(i1) ? true : false;
}

bool InterventionRecord::removeIntervention(Intervention i1) {
    return interventions.remove(i1) ? true : false;
}

