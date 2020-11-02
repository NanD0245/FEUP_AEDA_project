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

/*class Motorbike:public Vehicle{
public:
    Motorbike();
    int getClass() const {return 0;}
    string getInfo();
};

class Car:public Vehicle{
public:
    Car();
    int getClass() const {return 1;}
    string getInfo();
};

class HeavyPassengers:public Vehicle{
public:
    HeavyPassengers();
    int getClass() const {return 2;}
    string getInfo();
};

class HeavyMerch:public Vehicle{
public:
    HeavyMerch();
    int getClass() const {return 3;}
    string getInfo();
};*/


#endif //AEDA2020_PORTAGENS_VEHICLE_H
