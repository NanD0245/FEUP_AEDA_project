//
// Created by mim on 24/10/20.
//

#include "SystemNetwork.h"

using namespace std;

SystemNetwork::SystemNetwork() {
    highways = new Highways();
    movements = new Movements();
}

void SystemNetwork::read(string file){

}
void SystemNetwork::write(string file){
    vector<Toll *> t;
    vector<Lane *> l;
    ofstream f(file);

    for (int i = 0;i<highways->highways.size();i++){
        f<< "Highway nr"<<i+1<<": ";
        f << highways->highways[i]->getName() <<endl;
        t= highways->highways[i]->tolls;
        for(int j=0;j<t.size();j++){
            f<< "  Toll nr"<<j+1<<endl;
            f<<"  "<<t[j]->getInfo();
            l=t[j]->lanes;
            for(int k=0;k<l.size();k++){
                f<< "    Lane nr"<<l[k]->getLaneNumber()<<endl;
                f<<l[k]->getInfo();
            }
        }
    }
    for(int i=0;i<movements->movements.size();i++){
        f<<"Movement nr"<<i+1<<": "<<endl;
        f<<movements->movements[i]->getInfo();
    }

    f.close();
}