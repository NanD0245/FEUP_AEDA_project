#ifndef AEDA2020_PORTAGENS_TOLLS_H
#define AEDA2020_PORTAGENS_TOLLS_H

#include "Lane.h"
#include <string>
#include <vector>

using namespace std;

class Toll {
    string name;
    string geolocal;
    float highway_kilometer;
    bool type;
    vector<Lane *> lanes;

public:
    Toll(string name, string geolocal, float highway_kilometer, string type);
    string getName() const;
    string getGeolocal() const;
    float getKilometer() const;
    bool getType() const;
    string getInfo() const;
    int count() const;
    Lane * getLane(Lane * l1);
    bool addGreenLane();
    bool addEmployeeLane(Employee *E);
    bool addEntranceLane();
    bool addLane(Lane * l1);
    bool removeLane(Lane * l1);
    bool operator==(const Toll& l2) const;
};

/*class TollEntrance : public Toll {

};

class TollOut : public Toll {
    TollOut(string name, string geolocal, float highway_kilometer, string type);
};*/



#endif //AEDA2020_PORTAGENS_TOLL_H
