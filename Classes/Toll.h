
#ifndef AEDA2020_PORTAGENS_TOLLS_H
#define AEDA2020_PORTAGENS_TOLLS_H

#include "Lane.h"
#include <string>
#include <vector>

using namespace std;

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
    void setLaneNumber(Lane * lane, int new_lane_number);
    void setGreenLaneTrue(Lane * lane);
    void setGreenLaneFalse(Lane * lane, Employee* e);
    virtual void addLane() {};
    virtual void addLane(Lane * l);
    virtual void addLane(Employee * e) {};
    int getNumLanes() const;
    Lane * getLane(int i);
    bool removeLane(int i);
    bool operator==(const Toll& l2) const;
    friend class SystemNetwork;

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