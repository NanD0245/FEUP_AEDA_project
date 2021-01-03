/*#include <iostream>
//#include "Classes/Toll.h"
#include "Classes/EmployeeRecord.h"
#include "Classes/VehicleRecord.h"
#include "Classes/Date.h"
#include "Classes/HighwayRecord.h"
#include "Classes/MovementRecord.h"*/
#include "Classes/SystemNetwork.h"

#define file "../Cache/systemNetworks.txt"

#ifdef _WIN32
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <wincon.h>

// Fix compilatin on MinGW
#ifndef DISABLE_NEWLINE_AUTO_RETURN
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_INPUT
#define ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
/**
 * configura a consola no Windows de modo a que os ASCII codes sejam aceites. Código retirado do Microsoft Docs:
 * https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#example-of-enabling-virtual-terminal-processing
 * Set output mode to handle virtual terminal sequences
 * @return false if it couldn't create the console, true otherwise
 */
bool SetupConsole() {

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) {
		return false;
	}
	DWORD dwOriginalInMode = 0;
	DWORD dwOriginalOutMode = 0;
	if (!GetConsoleMode(hIn, &dwOriginalInMode)) {
		return false;
	}
	if (!GetConsoleMode(hOut, &dwOriginalOutMode)) {
		return false;
	}
	DWORD dwInMode = dwOriginalInMode | ENABLE_VIRTUAL_TERMINAL_INPUT;
	if (!SetConsoleMode(hIn, dwInMode))
	{
		// Failed to set VT input mode, can't do anything here.
		return false;
	}
	DWORD dwOutMode = dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
	if (!SetConsoleMode(hOut, dwOutMode)) {
		// we failed to set both modes, try to step down mode gracefully.
		dwOutMode = dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwOutMode))
		{
			// Failed to set any VT mode, can't do anything here.
			return false;
		}
	}
	return true;
}
#endif //_WIN32

using namespace std;

int main(int argc, char* argv[]) {
    #ifdef _WIN32
        SetupConsole();
    #endif

    SystemNetwork system;
    Utils utils;
    int index;

    system.read(file);





    /*system.highways->addHighway("A1");
    Highway* h1 = system.highways->getHighwayIndex(0);
    system.highways->addHighway("A2");
    Highway* h2 = system.highways->getHighwayIndex(1);
    system.vehicles->setTaxes(0.12,0.15,0.20,0.30);
    system.employees->addEmployee("Fernando");
    Employee* e1 = system.employees->getEmployee("Fernando");
    system.employees->addEmployee("Luis");
    Employee* e2 = system.employees->getEmployee("Luis");
    system.employees->addEmployee("Santos");
    Employee* e3 = system.employees->getEmployee("Santos");
    system.employees->addEmployee("Rego");
    Employee* e4 = system.employees->getEmployee("Rego");
    system.vehicles->addVehicle("A1",1,true);
    Vehicle* v1 = system.vehicles->getVehicleIndex(0);
    system.vehicles->addVehicle("A2",2, false);
    Vehicle* v2 = system.vehicles->getVehicleIndex(1);
    system.vehicles->addVehicle("A3",2, false);
    Vehicle* v3 = system.vehicles->getVehicleIndex(2);
    system.vehicles->addVehicle("A4",3, true);
    Vehicle* v4 = system.vehicles->getVehicleIndex(3);
    system.vehicles->addVehicle("A5",4,true);
    Vehicle* v5 = system.vehicles->getVehicleIndex(4);
    system.highways->getHighwayIndex(0)->addToll("P1","Porto", 0.5, false);
    Toll* t1 = system.highways->getHighwayIndex(0)->getTollIndex(0);
    system.highways->getHighwayIndex(0)->addToll("P2","Porto", 0.5, true);
    Toll* t2 = system.highways->getHighwayIndex(0)->getTollIndex(1);
    system.highways->getHighwayIndex(0)->addToll("P4","Aveiro", 55.3, false);
    Toll* t3 = system.highways->getHighwayIndex(0)->getTollIndex(2);
    system.highways->getHighwayIndex(0)->addToll("P3","Aveiro", 55.6, true);
    Toll* t4 = system.highways->getHighwayIndex(0)->getTollIndex(3);
    system.highways->getHighwayIndex(1)->addToll("P1","Lisboa", 0.3, false);
    Toll* t5 = system.highways->getHighwayIndex(1)->getTollIndex(0);
    system.highways->getHighwayIndex(1)->addToll("P2","Lisboa", 0.7, true);
    Toll* t6 = system.highways->getHighwayIndex(1)->getTollIndex(1);
    system.highways->getHighwayIndex(1)->addToll("P4","Algarve", 159.3, false);
    Toll* t7 = system.highways->getHighwayIndex(1)->getTollIndex(2);
    system.highways->getHighwayIndex(1)->addToll("P3","Algarve", 159.2, true);
    Toll* t8 = system.highways->getHighwayIndex(1)->getTollIndex(3);
    system.highways->getHighwayIndex(0)->getTollIndex(0)->addLane();
    Lane* l1 = system.highways->getHighwayIndex(0)->getTollIndex(0)->getLane(0);
    system.highways->getHighwayIndex(0)->getTollIndex(0)->addLane();
    Lane* l2 = system.highways->getHighwayIndex(0)->getTollIndex(0)->getLane(1);
    system.highways->getHighwayIndex(0)->getTollIndex(1)->addLane(system.employees->getEmployee("Fernando"));
    Lane* l3 = system.highways->getHighwayIndex(0)->getTollIndex(1)->getLane(0);
    system.highways->getHighwayIndex(0)->getTollIndex(1)->addLane();
    Lane* l4 = system.highways->getHighwayIndex(0)->getTollIndex(1)->getLane(1);
    system.highways->getHighwayIndex(0)->getTollIndex(2)->addLane();
    Lane* l5 = system.highways->getHighwayIndex(0)->getTollIndex(2)->getLane(0);
    system.highways->getHighwayIndex(0)->getTollIndex(2)->addLane();
    Lane* l6 = system.highways->getHighwayIndex(0)->getTollIndex(2)->getLane(1);
    system.highways->getHighwayIndex(0)->getTollIndex(3)->addLane(system.employees->getEmployee("Luis"));
    Lane* l7 = system.highways->getHighwayIndex(0)->getTollIndex(3)->getLane(0);
    system.highways->getHighwayIndex(0)->getTollIndex(3)->addLane();
    Lane* l8 = system.highways->getHighwayIndex(0)->getTollIndex(3)->getLane(1);
    system.highways->getHighwayIndex(1)->getTollIndex(0)->addLane();
    Lane* l9 = system.highways->getHighwayIndex(1)->getTollIndex(0)->getLane(0);
    system.highways->getHighwayIndex(1)->getTollIndex(0)->addLane();
    Lane* l10 = system.highways->getHighwayIndex(1)->getTollIndex(0)->getLane(1);
    system.highways->getHighwayIndex(1)->getTollIndex(1)->addLane();
    Lane* l11 = system.highways->getHighwayIndex(1)->getTollIndex(1)->getLane(0);
    system.highways->getHighwayIndex(1)->getTollIndex(1)->addLane(system.employees->getEmployee("Santos"));
    Lane* l12 = system.highways->getHighwayIndex(1)->getTollIndex(1)->getLane(1);
    system.highways->getHighwayIndex(1)->getTollIndex(2)->addLane();
    Lane* l13 = system.highways->getHighwayIndex(1)->getTollIndex(2)->getLane(0);
    system.highways->getHighwayIndex(1)->getTollIndex(2)->addLane();
    Lane* l14 = system.highways->getHighwayIndex(1)->getTollIndex(2)->getLane(1);
    system.highways->getHighwayIndex(1)->getTollIndex(3)->addLane(system.employees->getEmployee("Rego"));
    Lane* l15 = system.highways->getHighwayIndex(1)->getTollIndex(3)->getLane(0);
    system.highways->getHighwayIndex(1)->getTollIndex(3)->addLane();
    Lane* l16 = system.highways->getHighwayIndex(1)->getTollIndex(3)->getLane(1);
    Date* d1 = new Date("12/5/2020 20:00:05");
    Date* d2 = new Date("12/5/2020 23:30:00");
    Date* d3 = new Date("12/5/2020 8:00:05");
    Date* d4 = new Date("12/5/2020 11:30:00");
    system.movements->addMovement(new MovementEntry(v1,h1,t1,l1,d3)); //v1,v4,v5;  l3,l7,l12,l15
    system.movements->addMovement(new MovementEntry(v3,h1,t3,l5,d1));
    system.movements->addMovement(new MovementOut(v3,h1,t2,l3,d2,system.movements->getMovementIndex(1)));
    system.movements->addMovement(new MovementEntry(v3,h1,t1,l1,d1));
    system.movements->addMovement(new MovementOut(v1,h1,t4,l7,d4,system.movements->getMovementIndex(0)));
    system.movements->addMovement(new MovementOut(v3,h1,t4,l8,d1,system.movements->getMovementIndex(3)));
    system.movements->addMovement(new MovementEntry(v4,h2,t5,l9,d1));
    system.movements->addMovement(new MovementOut(v4,h2,t8,l15,d1,system.movements->getMovementIndex(6)));
    system.movements->addMovement(new MovementEntry(v5,h2,t7,l14,d1));
    system.movements->addMovement(new MovementOut(v5,h2,t6,l11,d1,system.movements->getMovementIndex(8)));
    Technician* a = new Technician("Fernando", "review");
    t1->addTechnician(a);
    Technician* b = new Technician("Luis", "informatic");
    t1->addTechnician(b);
    Technician* c = new Technician("Santos", "informatic");
    t5->addTechnician(c);
    Technician* d = new Technician("Rego", "eletronic");
    t5->addTechnician(d);
    Intervention* A = new Intervention("informatic",h1,t2,d1,d2,b,*d2 - *d1,true);
    Intervention* B = new Intervention("informatic",h2,t6,d3,d4,c,*d4 - *d3,true);
    Intervention* C = new Intervention("informatic",h1,t1,d1,d2,b,*d2 - *d1,true);
    Intervention* D = new Intervention("informatic",h2,t1,d1,d2,b,*d2 - *d1,true);
    Intervention* E = new Intervention("review",h1,t2,d1,d2,b,*d2 - *d1,true);
    system.interventions->addIntervetion(*A);
    system.interventions->addIntervetion(*B);
    system.interventions->addIntervetion(*C);
    system.interventions->addIntervetion(*D);
    system.interventions->addIntervetion(*E);*/

    do {
        utils.clrScreen();

        index = utils.ShowMenu({"Manage Movements", "Manage Highways", "Manage Employees" , "Manage Vehicles",
                                "Input Taxes for vehicles", "Manage Interventions", "Manage Technicians",
                                "Manage Owners", "Statistics"});
        switch (index) {
            case(1):
                system.manageMovements();
                break;
            case(2):
                system.manageHighways();
                break;
            case(3):
                system.manageEmployee();
                break;
            case(4):
                system.manageVehicle();
                break;
            case 5:
                system.getTaxesFromUser();
                break;
            case 6:
                system.manageInterventions();
                break;
            case 7:
                system.manageTechnicians();
                break;
            case 8:
                system.manageOwners();
                break;
            case 9:
                system.manageStatistics();
                break;
        }
    } while (index);
    system.write();
    return 0;
}