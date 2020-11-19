#include "Vehicles.h"

using namespace std;

Vehicles::Vehicles() {
    vehicles.clear();
    for (int i = 0; i < 4; i++) {
        taxes[i] = -1;
    }
}

int Vehicles::getNumVehicles() const {return vehicles.size();}

float Vehicles::getTaxes(int v_class) {return taxes[v_class-1];}

Vehicle * Vehicles::getVehicle(string plate) {
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getPlate() == plate) {
            return vehicles[i];
        }
    }
    return nullptr;
}

Vehicle * Vehicles::getVehicleIndex(int i) {
    if (i < vehicles.size())
        return vehicles[i];
    return nullptr;
}

void Vehicles::setTaxes(float a, float b, float c, float d) {
    taxes[0] = a;
    taxes[1] = b;
    taxes[2] = c;
    taxes[3] = d;
}

bool Vehicles::checkPlate(string plate) {
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getPlate() == plate)
            return true;
    }
    return false;
}

bool Vehicles::addVehicle(string plate, int v_class) {
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getPlate() == plate) {
            cout << "Existe um veiculo com a mesma matricula" << endl;
            return false;
        }
    }
    auto * a1 = new Vehicle(plate,v_class,taxes[v_class-1]);
    vehicles.push_back(a1);
    return true;
}

bool Vehicles::addVehicle(string plate, int v_class, bool greenlane) {
    if (addVehicle(plate,v_class)) {
        vehicles[vehicles.size()-1]->defineLaneType(greenlane);
        return true;
    }
    return false;
}

bool Vehicles::removeVehicle(int i) {
    if (i >= vehicles.size())
        return false;
    vehicles.erase(vehicles.begin()+i);
    return true;
}
