#include "Toll.h"
#include <iostream>

using namespace std;

Toll::Toll(string name, string geolocal, string type) : name(name), geolocal(geolocal), type(type) {
    if (type == "entrance") {

    }
    else if (type == "exit") {

    }
}

void Toll::printHello() {
    cout << "Hello World!" << endl;
}
