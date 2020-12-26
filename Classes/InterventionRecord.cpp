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

vector<string> InterventionRecord::showInterventions() {
    vector<string> v;
    for (auto it = BSTItrIn<Intervention>(interventions); !it.isAtEnd(); it.advance()){
        Intervention i = it.retrieve();
        string s = i.showIntervention();
        v.push_back(s);
    }
    return v;
}

vector<string> InterventionRecord::showInterventionsNotConcluded() {
    vector<string> v;
    for (auto it = BSTItrIn<Intervention>(interventions); !it.isAtEnd(); it.advance()){
        if (!it.retrieve().getState()) {
            Intervention i = it.retrieve();
            string s = i.showIntervention();
            v.push_back(s);
        }
    }
    return v;
}

Intervention InterventionRecord::getIntervention(int indexIn) {
    for (auto it = BSTItrIn<Intervention>(interventions); !it.isAtEnd(); it.advance()){
        if (!indexIn)
            return it.retrieve();
        indexIn--;
    }
    return Intervention("", nullptr, nullptr, nullptr, nullptr);
}
