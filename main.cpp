#include <iostream>
#include "Classes/Toll.h"

#include "Classes/Vehicles.h"
#include "Classes/Date.h"
#include "Classes/Highways.h"
#include "Classes/Movements.h"

using namespace std;

int main() {
    Vehicles v1;
    v1.addVehicle("AA-02-03",1);
    v1.addVehicle("AG-32-06",1,1);
    v1.addVehicle("AA-02-04",1);
    v1.addVehicle("AA-02-06",1,true);
    v1.addVehicle("AA-02-03",1);
    for (size_t i = 0; i < v1.getNumVehicles(); i++) {
        cout << v1.getVehicle(i)->getPlate() << endl;
    }
    return 0;
}