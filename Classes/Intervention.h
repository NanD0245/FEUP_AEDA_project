//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_INTERVENTION_H
#define AEDA2020_PORTAGENS_INTERVENTION_H

#include <iostream>
#include "Date.h"
#include "HighwayRecord.h"
#include "Technician.h"

class Intervention {
    string type; // revisão ; avaria(eletrónica ; informática)
    Highway* highway;
    Toll* toll;
    Date* start_date, *end_date;
    Technician* technician;
    float duration;
    bool state; // em espera ; concluido
public:
    Intervention(string type, Technician* technician, Date* date, Highway* highway, Toll* toll);
    void concludeIntervention(Date* end_date);
    string getType() const;
    void setType(string type);
    Highway * getHighway() const;
    Toll* getToll() const;
    bool getState() const;
    void changeState();
    Date* getStartDate() const;
    Date* getEndDate() const;
    float getDuration() const;
    void setDuration(float duration);
    string showIntervention();
    string getInfo();
    bool operator<(const Intervention& i1) const;
};


#endif //AEDA2020_PORTAGENS_INTERVENTION_H
