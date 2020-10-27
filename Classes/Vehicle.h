//
// Created by mim on 22/10/20.
//

#ifndef AEDA2020_PORTAGENS_VEHICLE_H
#define AEDA2020_PORTAGENS_VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
    string plate;
    bool lanetype;
    float distance;
    //int road;
public:
    Vehicle(string plate, int v_class);
    void defineLaneType(string lt);
    int getBestLane();

    float getDistance(){return distance;}const;
    virtual int getClass(){} const;
    string getPlate(){return plate;}const;
    bool getLaneType(){return lanetype;}const;
};

class Motorbike:public Vehicle{
    float tax;
public:
    Motorbike();
    int getClass(){return 1;} const;
};

class Car:public Vehicle{
    float tax;
public:
    Car();
    int getClass(){return 2;} const;
};

class HeavyPassengers:public Vehicle{
    float tax;
public:
    HeavyPassengers();
    int getClass(){return 3;} const;

};

class HeavyMerch:public Vehicle{
    float tax;
public:
    HeavyMerch();
    int getClass(){return 4;} const;
};


#endif //AEDA2020_PORTAGENS_VEHICLE_H
