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
    float distance;
    //int road;
public:
    Vehicle(string plate, int v_class);
    void defineLaneType(bool greenlane);
    int getBestLane();

    float getDistance() const {return distance;}
    //virtual int getClass() const;
    string getPlate() const {return plate;}
    bool getGreenLaneBool() const {return greenlane;}
};

class Motorbike:public Vehicle{
public:
    Motorbike();
    int getClass() const {return 1;}
};

class Car:public Vehicle{
public:
    Car();
    int getClass() const {return 2;}
};

class HeavyPassengers:public Vehicle{
public:
    HeavyPassengers();
    int getClass() const {return 3;}

};

class HeavyMerch:public Vehicle{
public:
    HeavyMerch();
    int getClass() const {return 4;}
};


#endif //AEDA2020_PORTAGENS_VEHICLE_H
