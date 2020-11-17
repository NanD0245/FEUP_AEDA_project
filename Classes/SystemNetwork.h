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
#include <algorithm>

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
    void manageReadMovements();
    void manageMovementsHighway();
    void manageMovementsToll();
    void manageMovementsLane();
    void manageMovementsCar();
    void manageStatistics();

    void createHighway();
    void readHighways();
    void updateHighway();
    void deleteHighway();
    Highway* chooseHighway();
    int chooseIndexHighway() const;

    void createToll(Highway * highway);
    void readTolls(Highway * highway);
    void updateToll(Highway * highway);
    void deleteToll(Highway * highway);
    int chooseIndexToll(Highway * highway) const;
    Toll* chooseToll(Highway* highway);

    void createLane(Toll* toll);
    void readLanes(Toll* toll);
    void updateLane(Toll* toll);
    void deleteLane(Toll* toll);
    int chooseIndexLane(Toll* toll) const;
    Lane* chooseLane(Toll* toll);

    void createEmployee();
    void readEmployees();
    void updateEmployee();
    void deleteEmployee();
    int chooseIndexEmployee() const;

    void createVehicle();
    void readVehicles();
    void updateVehicle();
    void deleteVehicle();
    int chooseIndexVehicle() const;

    int adviceEntryLane(Toll * toll, Date * date);
    int adviceOutLane(Vehicle* vehicle, Toll * toll, Date * date);
    void getTaxesFromUser();
    void addEntryMovement();
    void addExitMovement();
    void showMovementsByHighwayName(); //alphabetic + worth
    void showMovementsByHighwayPrice();
    void showMovementsByDate();
    void showMovementsByTollName(Highway* highway);//alphabetic + types + worth
    void showMovementsByTollType(Highway* highway);
    void showMovementsByTollPrice(Highway* highway);
    void showMovementsbyLaneNumber(Toll * toll); //worth
    void showMovementsbyLanePrice(Toll * toll);
    void showCarMovementsbyDate();
    void showCarMovementsbyDistance();
    void showCarMovementsbyPrice();
    void showEmployeeMovements();

    void carSpentMoreMoney();
    void BestWorthHighway();
    void BestWorthToll();
    void BestWorthLane();
    void HighwayMoreMoves();
    void TollMoreMoves();
    void LaneMoreMoves();

    void read(string file);
    void write();
    void ungetstr(ifstream &f);
};


#endif //AEDA2020_PORTAGENS_SYSTEMNETWORK_H
