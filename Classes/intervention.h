//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_INTERVENTION_H
#define AEDA2020_PORTAGENS_INTERVENTION_H

#include <iostream>
#include "Date.h"
#include "technician.h"

class Intervention {
    string type; // revisão ; avaria(eletrónica ; informática)
    Date date;
    Technician technician;
    float duration;
    bool state; // em espera ; concluido
public:
    Intervention(string type, Technician technician, Date date, float duration, bool state = 0);
    string getType() const;
    void setType(string type);
    Technician getTechnician() const;
    void setTechnician(Technician technician);
    bool getState() const;
    void changeState();
    Date getDate() const;
    float getDuration() const;
    void setDuration(float duration);
    bool operator<(Intervention i1);
};


#endif //AEDA2020_PORTAGENS_INTERVENTION_H
