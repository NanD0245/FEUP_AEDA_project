//
// Created by mim on 22/10/20.
//

#ifndef AEDA2020_PORTAGENS_VEHICLE_H
#define AEDA2020_PORTAGENS_VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
    string plate;
    int v_class;
    bool greenlane;
public:
    Vehicle(string plate, int v_class);
    void defineLaneType(bool greenlane);
    string getPlate() const {return plate;}
    bool getGreenLaneBool() const {return greenlane;}
    int getClass() const {return v_class;}
    string getInfo() const;
};


#endif //AEDA2020_PORTAGENS_VEHICLE_H
