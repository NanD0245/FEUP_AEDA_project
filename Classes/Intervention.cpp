//
// Created by mim on 15/12/20.
//

#include "Intervention.h"

Intervention::Intervention(string type, Technician* technician, Date* date, Highway* highway, Toll* toll) : type(type),
                                technician(technician), start_date(date), end_date(nullptr), highway(highway), toll(toll) {
    duration = -1;
    state = false;
};

Intervention::Intervention(string type, Highway *highway, Toll *toll, Date *start_date, Date *end_date,
                           Technician *technician, float duration, bool state) : type(type),
                            technician(technician), start_date(start_date), end_date(end_date), highway(highway), toll(toll) ,
                            duration(duration) , state(state) {}

string Intervention::getType() const {return type; }

void Intervention::setType(string type) {this->type = type; }

float Intervention::getDuration() const {return duration; }

void Intervention::setDuration(float duration) {this->duration = duration; }

bool Intervention::getState() const {return state; }

void Intervention::changeState() {state = !state; }

Date* Intervention::getStartDate() const {return start_date; }

Date* Intervention::getEndDate() const {return end_date; }

Highway * Intervention::getHighway() const {return highway; }

Toll * Intervention::getToll() const {return toll; }

bool Intervention::operator<(const Intervention& i1) const {
    cout << start_date->getInfo() << " - " << end_date->getInfo() << endl;
    if (*start_date < *i1.getStartDate()) {
        cout << "entrei1"<< endl;
        return true;}
    else if (*start_date == *i1.getStartDate() && highway->getInfo() < i1.getHighway()->getInfo()) {
        cout << "entrei2" << endl;
        return true;
    }
    else if (*start_date == *i1.getStartDate() && highway->getInfo() == i1.getHighway()->getInfo() && toll->getName() < i1.getToll()->getName()) {
        cout << "entrei3" << endl;
        return true;
    }
    else if (*start_date == *i1.getStartDate() && highway->getInfo() == i1.getHighway()->getInfo() && toll->getName() == i1.getToll()->getName()) {
        cout << "entrei4" << endl;
        if (type == "review")
            return true;
        else if (i1.getType() == "informatic")
            return true;
        else if (type == "informatic")
            return false;
        else if (i1.getType() == "review")
            return false;
    }
    return false;
}

string Intervention::showIntervention() {
    string s = "Start Date: " + start_date->getInfo() + " - Specialty: " + type + " - " + highway->showHighway() +
            " - Toll Name: " + toll->getName() + " - Technician: " + technician->showTechnician();
    if (state)
        s += "\n\t\tEnd Date: " + end_date->getInfo() + " - Duration: " + to_string(duration);
    return s;
}

void Intervention::concludeIntervention(Date *endDate) {
    this->end_date = endDate;
    duration = *end_date - *start_date;
    float time = technician->getPerformance() * technician->getNumIntervetion() + duration;
    technician->addIntervention();
    int num = technician->getNumIntervetion();
    technician->setPerformance(time/num);
    state = true;
}

string Intervention::getInfo() const{
    return type + " - " + highway->getInfo() + " - " + toll->getName() + " - " + start_date->getInfo() + " - " + end_date->getInfo() + " - " + technician->getName()+ " - " + to_string(duration) + " - " + to_string(state);
}