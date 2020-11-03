#ifndef AEDA2020_PORTAGENS_SYSTEMNETWORK_H
#define AEDA2020_PORTAGENS_SYSTEMNETWORK_H

#include "Highways.h"
#include "Movements.h"
#include "Vehicles.h"

#include <iostream>
#include <fstream>

using namespace std;

class SystemNetwork {
    Highways* highways;
    Movements* movements;
    Vehicles* vehicles;

public:
    SystemNetwork();
    /*
     * Get Taxes
     *
     * CRUD Highway
     * CRUD Toll
     * CRUD Lane     * CRUD Vehicle
     * CRUD Employee
     * Find Employee
     *
     * Enter Toll
     * Leave Toll
     *
     * Search Movements/Prices/Distances of:
     *      Highway
     *      Toll
     *      Lane
     *      Vehicle
     *
     *
     */
    void read(string file);
    void write(string file);
};


#endif //AEDA2020_PORTAGENS_SYSTEMNETWORK_H
