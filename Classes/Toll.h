
#ifndef AEDA2020_PORTAGENS_TOLLS_H
#define AEDA2020_PORTAGENS_TOLLS_H

#include "Lane.h"
#include <string>
#include <vector>

using namespace std;

/**
 * The class Toll is a class that has information about each
 * and every toll
 *
 * Each toll has a name, a geographic localization, a certain length, a certain number of lanes
 * which have different amounts of vehicles. Besides that, the toll can be an entrance toll or an
 * exit toll.
 *
 */
class Toll {
protected:
    string name;
    string geolocal;
    float highway_kilometer;
    bool type;
    vector<Lane *> lanes;
public:
    Toll(string name, string geolocal, float highway_kilometer,bool type);
    Toll();
    string getName() const;
    void setName(string name);
    string getGeolocal() const;
    void setGeolocal(string geolocal);
    float getKilometer() const;
    void setKilometer(float kilometer);
    bool getType() const;
    void setType(bool type);
    string getInfo() const;
    string showToll() const;
    void setGreenLaneTrue(Lane * lane);
    void setGreenLaneFalse(Lane * lane, Employee* e);
    virtual void addLane() {};
    virtual void addLane(Lane * l);
    virtual void addLane(Employee * e) {};
    int getNumLanes() const;
    Lane * getLane(int i);
    bool removeLane(int i);
    bool operator==(const Toll& l2) const;

};

class TollEntrance : public Toll {
public:
    TollEntrance(string name, string geolocal, float highway_kilometer);
    void addLane();
    void addLane(Lane * l);
};

class TollOut : public Toll {
public:
    TollOut(string name, string geolocal, float highway_kilometer);
    void addLane();
    void addLane(Employee * e);
    void addLane(Lane * l);
};

#endif //AEDA2020_PORTAGENS_TOLL_H