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
    string getPlate() const {return plate;}
    bool getGreenLaneBool() const {return greenlane;}
    //virtual int getClass() const;
    //virtual string getInfo() const;
};

class Motorbike:public Vehicle{
public:
    Motorbike();
    int getClass() const {return 1;}
    string getInfo();
};

class Car:public Vehicle{
public:
    Car();
    int getClass() const {return 2;}
    string getInfo();
};

class HeavyPassengers:public Vehicle{
public:
    HeavyPassengers();
    int getClass() const {return 3;}
    string getInfo();
};

class HeavyMerch:public Vehicle{
public:
    HeavyMerch();
    int getClass() const {return 4;}
    string getInfo();
};


#endif //AEDA2020_PORTAGENS_VEHICLE_H
