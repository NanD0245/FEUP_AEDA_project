//
// Created by mim on 22/10/20.
//

#ifndef AEDA2020_PORTAGENS_VEHICLE_H
#define AEDA2020_PORTAGENS_VEHICLE_H

#include <string>

using namespace std;

/**
 * The Vehicle class is a class that gives information about
 * the vehicle its driver is using.
 *
 * @param plate
 * @param v_class
 * @param greenlane (bool) is true if the car driver would rather use green lanes than non green, and false otherwise
 * @param tax
 */
class Vehicle {
    string plate;
    int v_class;
    bool greenlane;
    float tax;
public:
    Vehicle(string plate, int v_class, float tax);
    void defineLaneType(bool greenlane);
    string getPlate() const {return plate;}
    bool getGreenLaneBool() const {return greenlane;}
    int getClass() const {return v_class;}
    float getTax() const {return tax;}
    string getInfo() const;
    string showVehicle() const;
    void setPlate(string plate);
    void setVehicleClass(int v_class);
    void setGreenLaneTrue();
    void setGreenLaneFalse();
};


#endif //AEDA2020_PORTAGENS_VEHICLE_H
