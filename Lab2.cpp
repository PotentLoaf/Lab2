// Adrian Ng
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "netlist.cc"
#include "gates.cc"
using namespace std;

////global variables
//LogicGate gate; 
//GateList gateList;
//
//LogicGate::LogicGate(void) {}
//void LogicGate::setGateID(int loc) { gateID = loc; }
//int LogicGate::getGateID(void) { return gateID; }
//void LogicGate::setGatePos(int loc) { gatePos = loc; }
//int LogicGate::getGatePos(void) { return gatePos; }
//
//GateList::GateList(void) {
//	numGates = 42;
//	for (int i = 0; i < 42; i++) {
//		gate.setGateID(i);
//		gate.setGatePos(i);
//		setPosArray(gate);
//	}
//}
//void GateList::setNumGates(int num) { numGates = num; }
//int GateList::getNumGates(void) { return numGates; }
//void GateList::setPosArray(LogicGate gate) { posArray[gate.getGatePos()] = gate; }
//LogicGate* GateList::getPosArray(void) { return posArray; }
//
//Net::Net(void) {}
//void Net::setStartGate(int value) { startGate = value; }
//void Net::setEndGate(int value) { endGate = value; }
//int Net::getStartGate(void) { return startGate; }
//int Net::getEndGate(void) { return endGate; }
//
//NetList::NetList(void) {
//	numNets = 100;
//
//}
//void NetList::readInNetList() {
//	ifstream inputFile("netlist.txt", ios::in);
//
//	int a, b;
//	int counter = 0;
//	Net net;
//
//	while (inputFile >> a >> b) {
//		net.setStartGate(a);
//		net.setEndGate(b);
//		netlist[counter];
//		counter++;
//	}
//
//}
//void NetList::printGateLocations() {
//	for (int i = 0; i < 42; i++) {
//		cout << "Gate: " << gateList.getPosArray()[i].getGateID() << " Pos: " << i << endl;
//	}
//}
//void NetList::greedyPlacement() {}
//int NetList::calcNetLength() {
//	int length = 0;
//
//	Net net;
//
//	for (int i = 0; i < numNets; i++) {
//		net.setStartGate(netList.getNetList())
//		length += abs()
//	}
//
//	return length;
//}
//void NetList::SA_Algorithm() {}

int main()
{
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