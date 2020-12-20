//
// Created by mim on 15/12/20.
//

#include "Intervention.h"

Intervention::Intervention(string type, Technician technician, Date date, float duration, bool state) : type(type),
                                technician(technician), date(date), duration(duration), state(state) {};

string Intervention::getType() const {return type; }

void Intervention::setType(string type) {this->type = type; }

Technician Intervention::getTechnician() const {return technician; }

void Intervention::setTechnician(Technician technician) {this->technician = technician; }

float Intervention::getDuration() const {return duration; }

void Intervention::setDuration(float duration) {this->duration = duration; }

bool Intervention::getState() const {return state; }

void Intervention::changeState() {state = !state; }

Date Intervention::getDate() const {return date; }

bool Intervention::operator<(Intervention i1) {
    if (date > i1.getDate())
        return true;
    //falta ordenar pela portagem
    //em caso de empate ordenar por revisão -> eletrónica ->informática
    return false;
}