#ifndef AEDA2020_PORTAGENS_TOLLS_H
#define AEDA2020_PORTAGENS_TOLLS_H

#include "Type.h"
#include "Lanes.h"
#include <string>
#include <vector>

using namespace std;

class Toll {
    /*
     * nome
     * localização geográfica
     * tipo (entrada/saida)
     * vias
    */
public:
    Toll(string name, string geolocal, string type);
    static void printHello();
};

class TollEntrance : public Toll {

};

class TollOut : public Toll {

};



#endif //AEDA2020_PORTAGENS_TOLL_H
