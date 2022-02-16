// Adrian Ng
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "netlist.h"
#include "gates.h"
using namespace std;

LogicGate::LogicGate(void) {}
void LogicGate::setGateID(int loc) { gateID = loc; }
int LogicGate::getGateID(void) { return gateID; }
void LogicGate::setGatePos(int loc) { gatePos = loc; }
int LogicGate::getGatePos(void) { return gatePos; }

GateList::GateList(void) {
	for (int i = 0; i < 42; i++) {
		posArray[i] = 0;
	}
}
void GateList::setNumGates(int num) { numGates = num; }
int GateList::getNumGates(void) { return numGates; }
void GateList::setPosArray(int* pos[42]) { posArray[42] = pos[42]; }
int* GateList::getPosArray(void) { return posArray[42]; }

Net::Net(void) {}
void Net::setStartGate(int value) { startGate = value; }
void Net::setEndGate(int value) { endGate = value; }
int Net::getStartGate(void) { return startGate; }
int Net::getEndGate(void) { return endGate; }

NetList::NetList(void) {}
void NetList::readInNetList() {}
void NetList::printGateLocations() {}
void NetList::greedyPlacement() {}
int NetList::calcNetLength() {}
void NetList::SA_Algorithm() {}

//Net netlist[NUM_NETS];
//GateList gatelayout;
//int numNets;

int main()
{
	//instantiate a netList that contains as data members the other classes
	NetList netList;
	//for consistency let's use a common seed
	srand(2022);
	//read in the structures from netlist.txt
	netList.readInNetList();
	//initial regular placement
	cout << "The initial total net length is : " << netList.calcNetLength() << endl;
	netList.printGateLocations();
	cout << endl;
	//Greedy Optimization
	netList.greedyPlacement();
	cout << "The total net length after greedy placement : " << netList.calcNetLength() << endl;
	netList.printGateLocations();
	cout << endl;
	//Simulated Annealing Algorithm
	netList.SA_Algorithm();
	cout << "The total net length after SA placement : " << netList.calcNetLength() << endl;
	netList.printGateLocations();
}