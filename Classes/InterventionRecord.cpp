//
// Created by mim on 15/12/20.
//

#include "InterventionRecord.h"

InterventionRecord::InterventionRecord() : interventions(Intervention("", nullptr, nullptr, nullptr, nullptr)) {}

bool InterventionRecord::addIntervetion(const Intervention& i1) {
    return interventions.insert(i1) ? true : false;
}

bool InterventionRecord::removeIntervention(const Intervention& i1) {
    return interventions.remove(i1) ? true : false;
}

