//
// Created by mim on 22/10/20.
//

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(string plate, int v_class, float tax): plate(plate), v_class(v_class), tax(tax) {}

void Vehicle::defineLaneType(bool greenlane){this->greenlane=greenlane;}

string Vehicle::getInfo() const {
    return plate + " - " + to_string(v_class) + " - " + to_string(greenlane);
}


