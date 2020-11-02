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
    //bool removeVehicle(string plate);
    Vehicle * getVehicle(string plate);
    Vehicle * getVehicle(int i);
    void setTaxes(float a, float b, float c, float d);
};


#endif //AEDA2020_PORTAGENS_VEHICLES_H
