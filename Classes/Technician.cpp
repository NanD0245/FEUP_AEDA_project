//
// Created by mim on 15/12/20.
//

#include "Technician.h"

Technician::Technician(string name, string specialty) : name(name), specialty(specialty) {
    performance = 0;
    num_intervetion = 0;
}

string Technician::getName() const {return name; }

void Technician::setName(string name) {this->name = name; }

string Technician::getSpecialty() const {return specialty; }

void Technician::setSpecialty(string specialty) {this->specialty = specialty; }

float Technician::getPerformance() const {return performance; }

void Technician::setPerformance(float performance) {this->performance = performance; }

int Technician::getNumIntervetion() const {return num_intervetion; }

void Technician::addIntervention() {num_intervetion++; }

bool Technician::operator<(const Technician& t1) const {
    return performance < t1.getPerformance();
}

