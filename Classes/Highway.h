#ifndef AEDA2020_PORTAGENS_HIGHWAY_H
#define AEDA2020_PORTAGENS_HIGHWAY_H

#include "Toll.h"

/**
 * Highway class is a class that aggregates different Tolls.
 *
 * Each toll's information is stored in their corresponding Toll object,
 * which is then processed in the vector 'tolls' using Highway's methods.
 *
 * @param tolls contains all the Tolls that belong to the current Highway
 * @param name is the name of the Highway object
 */
class Highway {
    string name;
    vector<Toll *> tolls;
public:
    /**
     * The constructor of Highway class initializes the 'tolls' container as empty
     * @param name sets Highway's 'name'
     */
    Highway(string name);

    /**
     * @return object's name
     */
    string getName() const;

    string getInfo() const;

    /**
     * @return string with the format: "Highway Name:" + name
     */
    string showHighway() const;
    void setName(string new_name);
    int getNumTolls() const;
    Toll * getToll(string name);
    Toll * getTollIndex(int i);
    bool addToll(string name, string geolocal, float highway_kilometer,bool type);
    bool addToll(Toll *t);
    bool removeToll(Toll * t1);
    bool removeToll(int i);
    bool checkTollName(string name);
    bool operator==(const Highway &l2);
    /*
     * distancia entre 2 carros
     * preço
     * quantoas veiculos estao na autoestrada
     */
    friend class SystemNetwork; //apagar?
};


#endif //AEDA2020_PORTAGENS_HIGHWAY_H
