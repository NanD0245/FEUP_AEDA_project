//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_MOVEMENT_H
#define AEDA2020_PORTAGENS_MOVEMENT_H

#include "Vehicle.h"
#include "Highways.h"
#include "Date.h"

class Movement {
protected:
    bool type;
    Vehicle* vehicle;
    Highway* highway;
    Toll* toll;
    Lane* lane;
    Date* date;
public:


    Movement(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, string &date);
    bool getType() const;
    Vehicle * getVehicle() const;
    Highway * getHighway() const;
    Toll * getToll() const;
    Lane * getLane() const;
    Date * getDate() const;
    bool getType() const;
    string getDate() const;
    virtual string getInfo() const;
    void setType(const bool new_type);
    void setVehicle(const Vehicle* new_vehicle);
    void setHighway(const Highway* new_highway);
    void setToll(const Toll* new_toll);
    void setLane(const Lane* new_lane);
    void setDate(const string date);
    //virtual bool operator==(const Movement m1);
};

class MovementEntry : public Movement {
public:
    MovementEntry(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, Date* date);
    string getInfo() const;
    //bool operator==(const MovementEntry &m1);
};

class MovementOut : public Movement {
    MovementEntry * entry;
    float distance;
    float price;

public:
    MovementOut(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, Date* date, MovementEntry * entry, float distance, float price);
    MovementEntry * getEntry() const;
    float getDistance() const;
    float getPrice() const;
    string getInfo() const;
    //bool operator==(const MovementOut &m1);
};

#endif //AEDA2020_PORTAGENS_MOVEMENT_H
