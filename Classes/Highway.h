//
// Created by mim on 24/10/20.
//

#ifndef AEDA2020_PORTAGENS_HIGHWAY_H
#define AEDA2020_PORTAGENS_HIGHWAY_H

#include "Toll.h"

class Highway {
    string name;
    vector<Toll *> tolls;
public:
    Highway(string name);
    string getName() const;
    string getInfo() const;
    void setName(string new_name);
    int getNumTolls() const;
    Toll * getToll(string name);
    Toll * getTollIndex(int i);
    bool addToll(string name, string geolocal, float highway_kilometer,bool type);
    bool removeToll(Toll * t1);
    bool operator==(const Highway &l2);
    /*
     * distancia entre 2 carros
     * preço
     * quantoas veiculos estao na autoestrada
     */
};


#endif //AEDA2020_PORTAGENS_HIGHWAY_H
