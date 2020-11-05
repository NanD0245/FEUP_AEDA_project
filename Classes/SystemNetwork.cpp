//
// Created by mim on 24/10/20.
//

#include "SystemNetwork.h"

using namespace std;

SystemNetwork::SystemNetwork() {
    highways = new Highways();
    movements = new Movements();
    vehicles = new Vehicles();
    utils = new Utils();
    employees = new Employees();
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

void SystemNetwork::manageHighways() {
    int index;
    do {
        index = utils->ShowMenu({"Create Highway", "Update Highway", "Delete Highway", "Read Highways", "Manage Highway"});
        switch(index) {
            case 1:
                cout << "\033[2J\033[H";
                createHighway();
                break;
            case 2:
                cout << "\033[2J\033[H";
                updateHighway();
                break;
            case 3:
                cout << "\033[2J\033[H";
                deleteHighway();
                break;
            case 4:
                cout << "\033[2J\033[H";
                readHighways();
                break;
            case 5:
                auto *h1 = chooseHighway();
                if (h1 == nullptr)
                    break;
                manageHighway(h1);
                break;
        }
    } while(index);
}

void SystemNetwork::manageHighway(Highway* highway) {
    int index;
    do {
        index = utils->ShowMenu({"Create Toll", "Update Toll", "Delete Toll", "Read Tolls","Manage Toll"});
        switch(index) {
            case 1:
                cout << "\033[2J\033[H";
                createToll(highway);
                break;
            case 2:
                cout << "\033[2J\033[H";
                updateToll(highway);
                break;
            case 3:
                cout << "\033[2J\033[H";
                deleteToll(highway);
                break;
            case 4:
                cout << "\033[2J\033[H";
                readTolls(highway);
                break;
            case 5:
                cout << "\033[2J\033[H";
                auto *t1 = chooseToll(highway);
                if (t1 == nullptr)
                    break;
                manageToll(t1);
                break;
        }
    } while(index);
}

void SystemNetwork::manageToll(Toll *toll) {
    int index;
    do {
        index = utils->ShowMenu({"Create Lane", "Update Lane", "Delete Lane", "Read Lanes"});
        switch(index) {
            case 1:
                cout << "\033[2J\033[H";
                createLane(toll);
                break;
            case 2:
                cout << "\033[2J\033[H";
                updateLane(toll);
                break;
            case 3:
                cout << "\033[2J\033[H";
                deleteLane(toll);
                break;
            case 4:
                cout << "\033[2J\033[H";
                readLanes(toll);
                break;
        }
    } while(index);
}

void SystemNetwork::manageEmployee() {
    int index;
    do {
        index = utils->ShowMenu({"Create Employee", "Update Employee", "Delete Employee", "Read Employees"});
        switch(index) {
            case 1:
                cout << "\033[2J\033[H";
                createEmployee();
                break;
            case 2:
                cout << "\033[2J\033[H";
                updateEmployee();
                break;
            case 3:
                cout << "\033[2J\033[H";
                deleteEmployee();
                break;
            case 4:
                cout << "\033[2J\033[H";
                readEmployees();
                break;
        }
    } while(index);
}

void SystemNetwork::manageVehicle() {
    int index;
    do {
        index = utils->ShowMenu({"Register Vehicle", "Update Vehicle", "Delete Vehicle", "Read Vehicles"});
        switch(index) {
            case 1:
                cout << "\033[2J\033[H";
                createVehicle();
                break;
            case 2:
                cout << "\033[2J\033[H";
                updateVehicle();
                break;
            case 3:
                cout << "\033[2J\033[H";
                deleteVehicle();
                break;
            case 4:
                cout << "\033[2J\033[H";
                readVehicles();
                break;
        }
    } while(index);
}

void SystemNetwork::manageMovements() {
    int index;
    do {
        index = utils->ShowMenu({"Add a entry movement on a highway", "Add a exit movement of the highway"});
        switch(index) {
            case 1:
                cout << "\033[2J\033[H";
                addEntryMovement();
                break;
            case 2:
                cout << "\033[2J\033[H";
                addExitMovement();
                break;
        }
    } while(index);
}

void SystemNetwork::createHighway() {
    string s_name;
    while (s_name != "EXIT") {
        cout << "Input the highway name: (if you want to exit without create any highway please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name != "EXIT" && highways->addHighway(s_name)) {
            cout << "Highway created with success!" << endl;
            break;
        }
        cout << "ERROR: name of highway already exist." << endl;
    }
}

bool SystemNetwork::createHighway(string s_name) {
        return (s_name != "EXIT" && highways->addHighway(s_name));
}

void SystemNetwork::readHighways() {
    cout << "Highways: " << highways->getNumHighways() << endl;

    for (int i = 0; i < highways->getNumHighways(); i++) {
        cout << i+1 << " - " << highways->getHighwayIndex(i)->getName() << endl;
    }
}

void SystemNetwork::updateHighway() {
    string s_index, s_name;
    int index;
    readHighways();
    index = utils->getNumber(highways->getNumHighways())-1;
    if (index > -1)
        while (s_name != "EXIT") {
            cout << "Input the highway name: (if you want to exit without create any highway please input EXIT)" << endl;
            getline(cin, s_name);
            if (s_name != "EXIT" && highways->checkHighwayName(s_name)) {
                highways->getHighwayIndex(index)->setName(s_name);
                cout << "Highway updated with success!" << endl;
                break;
            }
            cout << "ERROR: name of highway already exist." << endl;
        }
}

bool SystemNetwork::updateHighway(int index, string s_name) {
    if (index > highways->getNumHighways()) return false;
    if (s_name != "EXIT" && highways->checkHighwayName(s_name)) {
        highways->getHighwayIndex(index)->setName(s_name);
        return true;
    }
    return false;
}

void SystemNetwork::deleteHighway() {
    string s_index, s_name;
    int index;
    readHighways();
    index = utils->getNumber(highways->getNumHighways())-1;
    if (index > -1)
        if (highways->removeHighway(index))
            cout << "Highway deleted with success!" << endl;
}

bool SystemNetwork::deleteHighway(int index) {
    if (index > highways->getNumHighways()) return false;
    return (highways->removeHighway(index));
}

Highway* SystemNetwork::chooseHighway() {
    int index;
    readHighways();
    index = utils->getNumber(highways->getNumHighways()) -1;
    while((index < -1)) {
        cout << "Invalid Number." << endl;
        index = utils->getNumber(highways->getNumHighways()) -1;
    }
    if (index == -1)
        return nullptr;
    return highways->getHighwayIndex(index);
}

void SystemNetwork::createToll(Highway *highway) {
    string s_name, s_geolocal;
    float kilometer;
    int i_type;
    bool type;
    while (!(s_name == "EXIT" || kilometer == -1 || i_type == 0)) {
        cout << "Input the toll's name: (if you want to exit without create any toll please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name != "EXIT" && highway->checkTollName(s_name)) {
            cout << "Input the toll's geographic location: (if you want to exit without create any toll please input EXIT)"<< endl;
            getline(cin, s_geolocal);
            if (s_geolocal != "EXIT") {
                cout << "Input the toll's highway kilometer: (if you want to exit without create any toll please input EXIT)"<< endl;
                kilometer = utils->getFloat();
                if (kilometer != -1) {
                    while(!(i_type == 1 || i_type == 2 || i_type == 0)) {
                        i_type = utils->ShowMenu({"Entrance - type","Exit - type"});
                    }
                    type = (i_type == 2);
                    if (i_type != 0) {
                        highway->addToll(s_name, s_geolocal, kilometer, type);
                        cout << "Toll created!" << endl;
                        break;
                    }
                }
            }
        }
        if(!(s_name == "EXIT" || kilometer == -1 || i_type == 0))
            cout << "ERROR: name of highway already exist." << endl;
    }
}



void SystemNetwork::readTolls(Highway* highway) {
    string s_type;
    cout << "Tolls: " << highway->getNumTolls() << endl;
    for (size_t i = 0; i < highway->getNumTolls(); i++) {
        s_type = highway->getTollIndex(i)->getType() ? "exit" : "entrance";
        cout << i+1 << " - " << highway->getTollIndex(i)->getName() << " " << highway->getTollIndex(i)->getGeolocal() << " " << highway->getTollIndex(i)->getKilometer() << " " + s_type << endl;
    }
}

void SystemNetwork::updateToll(Highway *highway) {
    int index, toll_index;
    float kilometer;
    string s_name;
    readTolls(highway);
    toll_index = utils->getNumber(highway->getNumTolls()) - 1;
    index = utils->ShowMenu({"Toll's name","Toll's geographic location", "Toll's highway kilometer", "Toll's type"});
    switch (index) {
        case 1:
            while (s_name != "EXIT") {
                cout << "Input the toll name: (if you want to exit without create any toll please input EXIT)" << endl;
                getline(cin, s_name);
                if (s_name != "EXIT" && highway->checkTollName(s_name)) {
                    highway->getTollIndex(toll_index)->setName(s_name);
                    cout << "Toll's name updated with success!" << endl;
                    break;
                }
                if (s_name!="EXIT")
                    cout << "ERROR: toll's name already exist." << endl;
            }
            break;
        case 2:
            cout << "Input the toll's geographic location: (if you want to exit without update any toll please input EXIT)" << endl;
            getline(cin, s_name);
            if (s_name != "EXIT") {
                highway->getTollIndex(toll_index)->setGeolocal(s_name);
                cout << "Toll's geographic location updated with success!" << endl;
                break;
            }
            break;
        case 3:
            kilometer = utils->getFloat();
            if (kilometer != -1)
                highway->getTollIndex(toll_index)->setKilometer(kilometer);
            break;
        case 4:
            if (highway->getTollIndex(toll_index)->getNumLanes() == 0)
                cout << "Not possible to update toll's type because the toll have at least one lane" << endl;
            else {
                do {
                    index = utils->ShowMenu({"Entrance", "Exit"});
                } while (!(index == 1 || index == 2 || index == 0));
                if (index != 0) { //warning errado pois index pode ser 0
                    highway->getTollIndex(toll_index)->setType(index == 2);
                }
            }
    }
}

void SystemNetwork::deleteToll(Highway *highway) {
    int toll_index;
    readTolls(highway);
    toll_index = utils->getNumber(highway->getNumTolls())-1;
    if (highway->removeToll(toll_index))
        cout << "Toll removed with success!" << endl;
}

Toll * SystemNetwork::chooseToll(Highway* highway) {
    int index;
    readTolls(highway);
    index = utils->getNumber(highway->getNumTolls()) -1;
    while((index < -1)) {
        cout << "Invalid Number." << endl;
        index = utils->getNumber(highway->getNumTolls()) -1;
    }
    if (index == -1)
        return nullptr;
    return highway->getTollIndex(index);
}

void SystemNetwork::createLane(Toll *toll) {
    int index;
    if (!toll->getType()) {
        toll->addLane();
        cout << "Lane created with success!" << endl;
    }
    else {
        index = utils->ShowMenu({"Normal lane", "Green lane"});
        if (index == 2) {
            toll->addLane();
            cout << "Lane created with success!" << endl;
        }
        else if (index == 1) {
            if (employees->getNumEmployees() == 0) {
                cout << "ERROR: It's necessary to have at least one employee to add a normal lane in a exit toll." << endl;
            }
            else {
                //readEmployees();
                index = utils->getNumber(employees->getNumEmployees())-1;
                if (index > -1) {
                    toll->addLane(employees->getEmployeeIndex(index));
                    cout << "Lane created with success!" << endl;
                }
            }
        }
    }
}

void SystemNetwork::readLanes(Toll *toll) {
    string s_type;
    cout << "Tolls: " << toll->getNumLanes() << endl;
    for (size_t i = 0; i < toll->getNumLanes(); i++) {
        s_type = toll->getLane(i)->getGreenLane() ? "Green lane" : "Normal lane";
        if (toll->getLane(i)->getEmployee() == nullptr)
            cout << i+1 << " - " << toll->getLane(i)->getLaneNumber() << " " << s_type;
        else
            cout << i+1 << " - " << toll->getLane(i)->getLaneNumber() << " " << s_type << " " << toll->getLane(i)->getEmployee()->getName() << " " << toll->getLane(i)->getEmployee()->getCode() << endl;
    }
}

void SystemNetwork::updateLane(Toll *toll) {
    int lane_index, index;
    if (toll->getType()) {
        readLanes(toll);
        lane_index = utils->getNumber(toll->getNumLanes())-1;
        if (toll->getLane(lane_index)->getGreenLane()) {
            index = utils->ShowMenu({"Green to normal lane"});
            if (index == 1) {
                //readEmployees();
                index = utils->getNumber(employees->getNumEmployees())-1;
                toll->setGreenLaneFalse(toll->getLane(lane_index),employees->getEmployeeIndex(index));
                cout << "Lane updated with success!" << endl;
            }
        }
        else {
            index = utils->ShowMenu({"Normal to GreenLane", "Lane's employee"});
            if (index == 1) {
                toll->setGreenLaneTrue(toll->getLane(lane_index));
                cout << "Lane updated with success!" << endl;
            }
            else if (index == 2) {
                //readEmployees();
                index = utils->getNumber(employees->getNumEmployees())-1;
                if (index > -1) {
                    toll->getLane(lane_index)->setEmployee(employees->getEmployeeIndex(index));
                    cout << "Lane's employee updated with success!" << endl;
                }
            }
        }
    }
    else {
        cout << "This is a entrance toll so there is nothing to update." << endl;
    }
}

void SystemNetwork::deleteLane(Toll *toll) {
    int lane_index;
    readLanes(toll);
    lane_index = utils->getNumber(toll->getNumLanes())-1;
    if (toll->removeLane(lane_index))
        cout << "Toll removed with success!" << endl;
}

Lane* SystemNetwork::chooseLane(Toll* toll) {
    int index, min ,counter = 0;
    readLanes(toll);
    index = utils->getNumber(toll->getNumLanes()) -1;
    while((index < -1)) {
        cout << "Invalid Number." << endl;
        index = utils->getNumber(toll->getNumLanes()) -1;
    }
    if (index == -1)
        return nullptr;
    return toll->getLane(index);
}

void SystemNetwork::createEmployee() {
    string s_name;
    while (s_name != "EXIT") {
        cout << "Input the employee name: (if you want to exit without create any employee please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name != "EXIT" && employees->addEmployee(s_name)) {
            cout << "employee created with success!" << endl;
            break;
        }
        if (s_name!= "EXIT")
            cout << "ERROR: name of employee already exist." << endl;
    }
}

void SystemNetwork::updateEmployee() {
    string s_index, s_name;
    int index;
    readEmployees();
    index = utils->getNumber(employees->getNumEmployees())-1;
    if (index > -1)
        while (s_name != "EXIT") {
            cout << "Input the employee name: (if you want to exit without create any employee please input EXIT)" << endl;
            getline(cin, s_name);
            if (s_name != "EXIT" && employees->checkEmployeeName(s_name)) {
                employees->getEmployeeIndex(index)->setName(s_name);
                cout << "Employee updated with success!" << endl;
                break;
            }
            if (s_name != "EXIT")
                cout << "ERROR: name of employee already exist." << endl;
        }
}

void SystemNetwork::deleteEmployee() {
    int index;
    readEmployees();
    index = utils->getNumber(employees->getNumEmployees())-1;
    if (index != -1) {
        employees->removeEmployee(index);
        cout << "Employee deleted with success!" << endl;
    }
}

void SystemNetwork::readEmployees() {
    cout << "Employees: " << employees->getNumEmployees() << endl;

    for (int i = 0; i <employees->getNumEmployees(); i++) {
        cout << i+1 << " - " << employees->getEmployeeIndex(i)->getName() << " " << employees->getEmployeeIndex(i)->getCode() << endl;
    }
}

void SystemNetwork::createVehicle() {
    string s_plate;
    int v_class, greenlane;
    while (s_plate != "EXIT") {
        cout << "Input the vehicle plate: (if you want to exit without create any vehicle please input EXIT)" << endl;
        getline(cin, s_plate);
        if (s_plate != "EXIT") {

            cout << "Choose one of the options of vehicle class: " << endl;
            v_class = utils->ShowMenu({"Classe 1 - Motas", "Classe 2 - Light vehicle (passengers or goods)", "Class 3 - Bus", "Class 4 - Heavy goods vehicle "});
            if (v_class != 0) {
                cout << "Choose one of the options: " << endl;
                greenlane = utils->ShowMenu({"To travel on Green lanes or Normal lanes", "To travel just on Normal lanes"});
                if (greenlane != 0) {
                    if (greenlane == 1) {
                        vehicles->addVehicle(s_plate,v_class,true);
                    }
                    else {
                        vehicles->addVehicle(s_plate,v_class);
                    }
                    cout << "Vehicle created with success!" << endl;
                    break;
                }
            }

        }
        if (!(s_plate == "EXIT" || v_class == 0 || greenlane == 0))
            cout << "ERROR: name of employee already exist." << endl;
    }
}

void SystemNetwork::updateVehicle() {
    string s_index, s_plate;
    int v_index,index;
    readVehicles();
    v_index = utils->getNumber(vehicles->getNumVehicles())-1;
    if (v_index > -1) {
        index = utils->ShowMenu({"Plate", "Vehicle class", "Type of lanes to travel"});
        switch (index) {
            case 1:
                while (s_plate != "EXIT") {
                    cout
                            << "Input the vehicle plate: (if you want to exit without create any vehicle please input EXIT)"
                            << endl;
                    getline(cin, s_plate);
                    if (s_plate != "EXIT" && vehicles->checkPlate(s_plate)) {
                        vehicles->getVehicleIndex(v_index)->setPlate(s_plate);
                        cout << "Vehicle updated with success!" << endl;
                        break;
                    }
                    if (s_plate != "EXIT")
                        cout << "ERROR: name of employee already exist." << endl;
                }
                break;
            case 2:
                cout << "Choose one of the options of vehicle class: " << endl;
                index = utils->ShowMenu({"Classe 1 - Motas", "Classe 2 - Light vehicle (passengers or goods)", "Class 3 - Bus", "Class 4 - Heavy goods vehicle "});
                if (index != 0) {
                    vehicles->getVehicleIndex(v_index)->setVehicleClass(index);
                    cout << "Vehicle updated with success!" << endl;
                }
                break;
            case 3:
                cout << "Choose one of the options: " << endl;
                index = utils->ShowMenu({"To travel on Green lanes or Normal lanes", "To travel just on Normal lanes"});
                if (index == 1) {
                    vehicles->getVehicleIndex(v_index)->setGreenLaneTrue();
                    cout << "Vehicle updated with success!" << endl;
                }
                else if (index == 2) {
                    vehicles->getVehicleIndex(v_index)->setGreenLaneFalse();
                    cout << "Vehicle updated with success!" << endl;
                }
                break;
        }
    }
}

void SystemNetwork::deleteVehicle() {
    int index;
    readVehicles();
    index = utils->getNumber(vehicles->getNumVehicles())-1;
    if (index <= -1) {
        vehicles->removeVehicle(index);
        cout << "Vehicle deleted with success!" << endl;
    }
}

void SystemNetwork::readVehicles() {
    string string1;
    cout << "Vehicles: " << vehicles->getNumVehicles() << endl;
    for (int i = 0; i < vehicles->getNumVehicles(); i++) {
        if (vehicles->getVehicleIndex(i)->getGreenLaneBool())
            string1 = "Exit";
        else string1 = "Entrance";
        cout << i+1 << " - " << vehicles->getVehicleIndex(i)->getPlate() << " " << vehicles->getVehicleIndex(i)->getClass() << " " << string1 << " " << vehicles->getVehicleIndex(i)->getTax()<< endl;
    }
}

void SystemNetwork::getTaxesFromUser() {
    float taxe[4];
    for (int i = 0; i < 4; i++) {
        cout << "Input the tax (euro per kilometer) for the class " << i+1 << endl;
        taxe[i] = utils->getFloat();
    }
    vehicles->setTaxes(taxe[0],taxe[1],taxe[2],taxe[3]);
}

int SystemNetwork::adviceEntryLane(Toll * toll, Date * date) {
    int min = -1, counter = 0, index;
    for (size_t i = 0; i < toll->getNumLanes(); i++) {
        counter = 0;
        for (size_t j = 0; j < movements->getNumMovements(); j++) {
            if (!movements->getMovementIndex(j)->getType()) {
                if (*(movements->getMovementIndex(j)->getDate()) == *date)
                    counter++;
            }
        }
        if (min == -1) {
            min = counter;
            index = i;
        }
        else if (counter < min) {
            min = counter;
            index = i;
        }
    }
    return index;
}

void SystemNetwork::addEntryMovement() {

    string s_plate;
    int index, lane_index;
    Vehicle* vehicle = nullptr;

    Highway* highway = nullptr;
    Toll *toll = nullptr;

    time_t timer = time(0);
    tm *now = localtime(&timer);
    string s_date = to_string(now->tm_mday) + "/" + to_string(now->tm_mon) + "/" + to_string(now->tm_year+1900)  + " " + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
    cout << s_date << endl;
    Date* date = new Date(s_date);

    if (movements->getNumMovements() == 0) {
        getTaxesFromUser();
    }
    while (s_plate != "EXIT" || index != 0) {
        cout << "Please input the plate of the vehicle: (if you want to exit without create any vehicle please input EXIT)" << endl;
        getline(cin, s_plate);
        while (s_plate.empty()) {
            cout << "ERROR: The plate can't be a empty string." << endl;
            getline(cin, s_plate);
        }
        if (s_plate == "EXIT") continue;
        if (!vehicles->checkPlate(s_plate)) {
            cout << "Vehicle is not registed. To advance input vehicle class" << endl;
            index = utils->ShowMenu({"Classe 1 - Motas", "Classe 2 - Light vehicle (passengers or goods)", "Class 3 - Bus", "Class 4 - Heavy goods vehicle "});
            if (index != 0)
                vehicle = new Vehicle(s_plate,index,vehicles->getTaxes(index));
            else continue;
        }
        else vehicle = vehicles->getVehicle(s_plate);
        do {
            highway = chooseHighway();
            if (highway == nullptr) {
                s_plate = "EXIT";
                break;
            }
            if (highway->getNumTolls() == 0) {
                cout << "ERROR: This highway don't have any toll." << endl;
            }
        } while (highway->getNumTolls() == 0);
        if (s_plate == "EXIT") continue;
        do {
            toll = chooseToll(highway);
            if (toll == nullptr) {
                s_plate = "EXIT";
                break;
            }
            if (toll->getNumLanes() == 0) {
                cout << "ERROR: This toll don't have any lane." << endl;
            }
        } while(toll->getNumLanes() == 0);
        if (s_plate == "EXIT") continue;
        lane_index = adviceEntryLane(toll, date);
        cout << "Our advice: Lane " << lane_index << ". (Lane with less traffic)" << endl;
        Lane *lane = chooseLane(toll);
        if (lane == nullptr) {
            s_plate = "EXIT";
            continue;
        }

        auto* m1 = new MovementEntry(vehicle, highway, toll, lane, date);
        movements->addMovement(m1);
        break;
    }
}

void SystemNetwork::addExitMovement() {
    string s_plate;
    int lane_index;
    Movement* entry = nullptr;
    Highway* highway = nullptr;
    Toll *toll = nullptr;
    while (s_plate != "EXIT") {
        cout << "Please input the plate of the vehicle: (if you want to exit without create any vehicle please input EXIT)" << endl;
        getline(cin, s_plate);
        while (s_plate.empty()) {
            cout << "ERROR: The plate can't be a empty string." << endl;
            getline(cin, s_plate);
        }
        if (s_plate == "EXIT") continue;
        cout << movements->getNumMovements() << endl;
        for (size_t i = movements->getNumMovements() - 1 ; i > -1; i-- ) {
            if (s_plate == movements->getMovementIndex(i)->getVehicle()->getPlate()) {
                if (!movements->getMovementIndex(i)->getType()) {
                    entry = movements->getMovementIndex(i);
                }
                break;
            }
        }
        if (entry == nullptr) {
            cout << "ERROR: Vehicle isn't in any highway." << endl;
            continue;
        }
        highway = entry->getHighway();
        do {
            toll = chooseToll(highway);
            if (toll == nullptr) {
                s_plate = "EXIT";
                break;
            }
            if (toll->getNumLanes() == 0) {
                cout << "ERROR: This toll don't have any lane." << endl;
            }
        } while(toll->getNumLanes() == 0);
        if (s_plate == "EXIT") continue;
        time_t timer = time(0);
        tm *now = localtime(&timer);
        string s_date = to_string(now->tm_mday) + "/" + to_string(now->tm_mon) + "/" + to_string(now->tm_year+1900)  + " " + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
        cout << s_date << endl;
        Date* date = new Date(s_date);
        lane_index = adviceEntryLane(toll, date);
        cout << "Our advice: Lane " << lane_index << ". (Lane with less traffic)" << endl;
        Lane *lane = chooseLane(toll);
        if (lane == nullptr) {
            s_plate = "EXIT";
            continue;
        }

        auto *m1 = new MovementOut(entry->getVehicle(),highway,toll,lane,date,entry);
    }
}
