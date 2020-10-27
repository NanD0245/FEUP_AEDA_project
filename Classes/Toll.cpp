#include "Toll.h"
#include <iostream>

using namespace std;

Toll::Toll(string name, string geolocal, float highway_kilometer,string type) : name(name), geolocal(geolocal), highway_kilometer(highway_kilometer) {
    if (type == "entrance") {
        this->type = true; // 1
    }
    else if (type == "exit") {
        this->type = false; // 0
    }
}

bool Toll::getType() const {return type;}

string Toll::getName() const {return name;}

string Toll::getGeolocal() const {return geolocal;}

float Toll::getKilometer() const {return highway_kilometer;}
