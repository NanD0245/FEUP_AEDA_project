#include <iostream>
//#include "Classes/Toll.h"
#include "Classes/Employees.h"
#include "Classes/Vehicles.h"
#include "Classes/Date.h"
#include "Classes/Highways.h"
#include "Classes/Movements.h"
#include "Classes/SystemNetwork.h"

using namespace std;

int main() {
    Highway a1 = Highway("A1");
    auto *e1 = new Employee("Fernando",0);
    a1.addToll("p1","Porto", 13.4, true);
    a1.getToll("p1")->addLane(e1);
    cout << a1.getToll("p1")->getLane(0)->getEmployee()->getInfo() << endl;
}