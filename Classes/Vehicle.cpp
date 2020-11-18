//
// Created by mim on 22/10/20.
//

#include "Vehicle.h"

using namespace std;

/**
 * Initializes plate, v_class and tax variables as the values inputted by the user when
 * the constructor is called
 *
 * @param plate
 * @param v_class
 * @param tax
 */
Vehicle::Vehicle(string plate, int v_class, float tax): plate(plate), v_class(v_class), tax(tax) {}

void Vehicle::defineLaneType(bool greenlane){this->greenlane=greenlane;}

/*!
 * @return current info about the vehicle: plate, the vehicle's class and if it uses green lanes
 */
string Vehicle::getInfo() const {
    return plate + " - " + to_string(v_class) + " - " + to_string(greenlane);
}

void Vehicle::setGreenLaneTrue() {greenlane = true;}

void Vehicle::setGreenLaneFalse() {greenlane = false;}

void Vehicle::setVehicleClass(int v_class) {this->v_class = v_class;}

void Vehicle::setPlate(string plate) {this->plate = plate;}
