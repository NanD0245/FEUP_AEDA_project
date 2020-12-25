//
// Created by mim on 15/12/20.
//

#include "Intervention.h"

Intervention::Intervention(string type, Technician* technician, Date* date, Highway* highway, Toll* toll) : type(type),
                                technician(technician), start_date(date), end_date(nullptr), highway(highway), toll(toll) {
    duration = -1;
    state = false;
};

string Intervention::getType() const {return type; }

void Intervention::setType(string type) {this->type = type; }

Technician* Intervention::getTechnician() const {return technician; }

void Intervention::setTechnician(Technician* technician) {this->technician = technician; }

float Intervention::getDuration() const {return duration; }

void Intervention::setDuration(float duration) {this->duration = duration; }

bool Intervention::getState() const {return state; }

void Intervention::changeState() {state = !state; }

Date* Intervention::getStartDate() const {return start_date; }

Date* Intervention::getEndDate() const {return end_date; }

Highway * Intervention::getHighway() const {return highway; }

Toll * Intervention::getToll() const {return toll; }

bool Intervention::operator<(const Intervention& i1) const {
    if (*start_date < *i1.getStartDate())
        return true;
    else if (start_date->equal(*i1.getStartDate()) && highway->getInfo() < i1.getHighway()->getInfo())
        return true;
    else if (start_date->equal(*i1.getStartDate()) && highway->getInfo() == i1.getHighway()->getInfo() && toll->getName() < i1.getToll()->getName())
        return true;
    else if (start_date->equal(*i1.getStartDate()) && highway->getInfo() == i1.getHighway()->getInfo() && toll->getName() == i1.getToll()->getName())
        return type < i1.getType();
    //falta ordenar pela portagem
    //em caso de empate ordenar por revisão -> eletrónica ->informática
    return false;
}