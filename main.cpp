#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>
//#include "Classes/Toll.h"
#include "Classes/Employees.h"
#include "Classes/Vehicles.h"
#include "Classes/Date.h"
#include "Classes/Highways.h"
#include "Classes/Movements.h"
#include "Classes/SystemNetwork.h"

using namespace std;

int main(int argc, char* argv[]) {
    /*testing::InitGoogleTest(&argc, argv);
    std::cout << "AEDA 2020/2021 - Practical 2 extra" << std::endl;
    return RUN_ALL_TESTS();*/
    SystemNetwork system;
    Utils utils;
    int index;
    system.createHighway("A1");
    system.createHighway("A2");
    system.createHighway("A3");
    system.createHighway("A4");
    system.highways->getHighwayIndex(2)->addToll("P1","Porto", 0, false);
    system.highways->getHighwayIndex(2)->addToll("P2","Aveiro", 0, true);
    system.highways->getHighwayIndex(2)->addToll("P3","Porto", 0, true);
    system.highways->getHighwayIndex(2)->addToll("P7","Aveiro", 0, false);

    do {
        cout << "\033[2J\033[H";
        index = utils.ShowMenu({"Manage Movements", "Manage Highways", "Manage Employees" ,"Manage Vehicles", "Statistics"});
        switch (index) {
            case(1):
                cout << "\033[2J\033[H";
                system.manageMovements();
                break;
            case(2):
                cout << "\033[2J\033[H";
                system.manageHighways();
                break;
            case(3):
                cout << "\033[2J\033[H";
                system.manageEmployee();
                break;
            case(4):
                cout << "\033[2J\033[H";
                system.manageVehicle();
                break;
            case 5:
                break;
        }
    } while (index);
    return 0;
}

