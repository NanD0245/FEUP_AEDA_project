#ifndef AEDA2020_PORTAGENS_TOLLS_H
#define AEDA2020_PORTAGENS_TOLLS_H

#include "Type.h"
#include "Lanes.h"
#include <string>
#include <vector>

class Toll {
    /*
     * nome
     * localização geográfica
     * tipo (entrada/saida)
     * vias
    */
    Type type;
    std::vector<Lanes> lanes;
public:
    static void printHello();
};


#endif //AEDA2020_PORTAGENS_TOLL_H
