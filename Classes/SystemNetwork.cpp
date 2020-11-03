//
// Created by mim on 24/10/20.
//

#include "SystemNetwork.h"

using namespace std;

SystemNetwork::SystemNetwork() {
    highways = new Highways();
    movements = new Movements();
    vehicles = new Vehicles();
}

void SystemNetwork::write(string file){
    vector<Toll *> t;
    vector<Lane *> l;
    ofstream f(file);

    for (int i = 0;i<highways->highways.size();i++){
        f<< "Highway nr"<<i+1<<": "<<endl;
        f << highways->highways[i]->getName() <<endl;
        t= highways->highways[i]->tolls;
        for(int j=0;j<t.size();j++){
            f<< "  Toll nr"<<j+1<<endl;
            f<<"  "<<t[j]->getInfo()<<endl;
            l=t[j]->lanes;
            for(int k=0;k<l.size();k++){
                f<< "    Lane nr"<<l[k]->getLaneNumber()<<endl;
                f<<"    "<<l[k]->getInfo()<<endl;
            }
        }
    }
    f<<endl;
    for(int i=0;i<movements->movements.size();i++){
        f<<"Movement nr"<<i+1<<": "<<endl;
        f<<movements->movements[i]->getInfo();
    }
    f<<endl;
    for(int i=0;i<vehicles->vehicles.size();i++){
        f<<"Taxes:";
        for (int j=0;j<4;j++){
            f<<" "<<vehicles->taxes[j];
        }
        f<<endl;
        f<<"Vehicle nr"<<i+1<<": "<<endl;
        f<<vehicles->vehicles[i]->getInfo()<<endl;
    }

    f.close();
}

void SystemNetwork::read(string file) {
    ifstream f(file);



    f.close();
}