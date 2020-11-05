//
// Created by mim on 31/10/20.
//

#ifndef AEDA2020_PORTAGENS_VEHICLES_H
#define AEDA2020_PORTAGENS_VEHICLES_H

#include "Vehicle.h"
#include <vector>
#include <iostream>

using namespace std;

class Vehicles {
    vector<Vehicle *> vehicles;
    float taxes[4];
public:
    Vehicles();
    int getNumVehicles() const;
    bool addVehicle(string plate, int v_class);
    bool addVehicle(string plate, int v_class, bool greenlane);
    bool removeVehicle(int i);
    Vehicle * getVehicle(string plate);
    Vehicle * getVehicleIndex(int i);
    void setTaxes(float a, float b, float c, float d);
    float getTaxes(int v_class);
    bool checkPlate(string plate);
    friend class SystemNetwork;
};

#endif //AEDA2020_PORTAGENS_VEHICLES_H
