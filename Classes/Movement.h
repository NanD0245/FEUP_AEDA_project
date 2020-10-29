//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_MOVEMENT_H
#define AEDA2020_PORTAGENS_MOVEMENT_H

#include "Vehicle.h"
#include "Highways.h"

class Movement {
    /*
     * bool type
     *
     * entrada:
     * veiculo
     * autoestrada + portagem + via (entrada)
     * hora
     *
     * saida:
     * veiculo
     * distancia
     * preço
     * (*)entrada
     * autoestrada + portagem + via (saida)
     * hora
     *
     */
protected:
    bool type;
    Vehicle* vehicle;
    Highway* highway;
    Toll* toll;
    Lane* lane;
    string date;
public:
    Movement(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, string &date);
    Vehicle * getVehicle() const;
    Highway * getHighway() const;
    Toll * getToll() const;
    Lane * getLane() const;
    string getDate() const;
    bool getType() const;
    virtual string getInfo() const;
    //virtual bool operator==(const Movement m1);
};

class MovementEntry : public Movement {
public:
    MovementEntry(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, string &date);
    string getInfo() const;
    //bool operator==(const MovementEntry &m1);
};

class MovementOut : public Movement {
    MovementEntry * entry;
    float distance;
    float price;

public:
    MovementOut(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, string &date, MovementEntry * entry, float distance, float price);
    MovementEntry * getEntry() const;
    float getDistance() const;
    float getPrice() const;
    string getInfo() const;
    //bool operator==(const MovementOut &m1);
};

#endif //AEDA2020_PORTAGENS_MOVEMENT_H
