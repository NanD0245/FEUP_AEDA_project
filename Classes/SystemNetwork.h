#ifndef AEDA2020_PORTAGENS_SYSTEMNETWORK_H
#define AEDA2020_PORTAGENS_SYSTEMNETWORK_H

#include "Highways.h"
#include "Movements.h"
#include "Vehicles.h"
#include "Employees.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class SystemNetwork {
public:
    Highways* highways;
    Movements* movements;
    Vehicles* vehicles;
    Utils* utils;
    Employees* employees;

    SystemNetwork();

    void manageHighways();
    void manageHighway(Highway * highway);
    void manageToll(Toll * toll);
    void manageEmployee();
    void manageVehicle();
    void manageMovements();

    void createHighway();
    void readHighways();
    void updateHighway();
    void deleteHighway();
    Highway* chooseHighway();
    bool createHighway(string s_name); //apenas para testes
    bool updateHighway(int index, string name); //apenas para testes
    bool deleteHighway(int index); //apenas para testes

    void createToll(Highway * highway);
    void readTolls(Highway * highway);
    void updateToll(Highway * highway);
    void deleteToll(Highway * highway);
    Toll* chooseToll(Highway* highway);

    void createLane(Toll* toll);
    void readLanes(Toll* toll);
    void updateLane(Toll* toll);
    void deleteLane(Toll* toll);
    Lane* chooseLane(Toll* toll);

    void createEmployee();
    void readEmployees();
    void updateEmployee();
    void deleteEmployee();

    void createVehicle();
    void readVehicles();
    void updateVehicle();
    void deleteVehicle();

    int adviceEntryLane(Toll * toll, Date * date);
    void getTaxesFromUser();
    void addEntryMovement();
    void addExitMovement();

    /*
     * Leave Toll
     *
     * Search Movements/Prices/Distances of:
     *      Highway
     *      Toll
     *      Lane
     *      Vehicle
     *
     */
    void read(string file);
    void write(string file);
};


#endif //AEDA2020_PORTAGENS_SYSTEMNETWORK_H
