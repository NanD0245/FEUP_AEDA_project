//
// Created by mim on 15/12/20.
//

#include "technician.h"

Technician::Technician(string name, string specialty) : name(name), specialty(specialty) {}

string Technician::getName() const {return name; }

void Technician::setName(string name) {this->name = name; }

string Technician::getSpecialty() const {return specialty; }

void Technician::setSpecialty(string specialty) {this->specialty = specialty; }

float Technician::getPerformance() const {return performance; }

void Technician::setPerformance(float performance) {this->performance = performance; }

