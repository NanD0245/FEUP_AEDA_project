#ifndef AEDA2020_PORTAGENS_SYSTEMNETWORK_H
#define AEDA2020_PORTAGENS_SYSTEMNETWORK_H

#include "Highways.h"
#include "Movements.h"
#include "Vehicle.h"

using namespace std;

class SystemNetwork {
    Highways* highways;
    Movements* movements;

public:
    SystemNetwork();
};


#endif //AEDA2020_PORTAGENS_SYSTEMNETWORK_H
