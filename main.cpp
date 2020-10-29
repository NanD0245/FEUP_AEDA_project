#include <iostream>
#include "Classes/Toll.h"

#include "Classes/Vehicle.h"
#include "Classes/Highways.h"
#include "Classes/Movements.h"
using namespace std;

int main() {
    auto *v1 = new Vehicle("AA", 1);
    auto *h1 = new Highway("A1");
    auto *t1 = new Toll("t1", "porto", 3, "entrance");
    auto *l1 = new Lane(0,true,false);
    string a = "2-3-12";
    Movement *m1 = new MovementEntry(v1, h1, t1, l1, a);
    return 0;
}