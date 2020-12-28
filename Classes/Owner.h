//
// Created by mim on 15/12/20.
//

#ifndef DATE_CPP_OWNER_H
#define DATE_CPP_OWNER_H

#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Owner {
    string name;
    vector<Vehicle*> vehicles;
public:
    Owner(string name);
    string getName() const;
    void setName(string name);
    int getNumVehicles() const;
    bool addVehicle(Vehicle* vehicle);
    bool addVehicle(string plate, int v_class, float tax);
    bool deleteVehicle(string plate);
    bool deleteVehicle(int index);
    vector<Vehicle*> getVehicles();
    vector<string> showVehicles();
    bool operator==(const Owner& o1);
};


#endif //DATE_CPP_OWNER_H
