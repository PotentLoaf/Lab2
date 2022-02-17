#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "gates.h"
#include "netlist.h"

using namespace std;

LogicGate::LogicGate(void) {}
void LogicGate::setGateID(int loc) { gateID = loc; }
int LogicGate::getGateID(void) { return gateID; }
void LogicGate::setGatePos(int loc) { gatePos = loc; }
int LogicGate::getGatePos(void) { return gatePos; }

GateList::GateList(void) {
	numGates = 42;
	LogicGate gate;

	for (int i = 0; i < 42; i++) {
		gate.setGateID(i);
		gate.setGatePos(i);
		setPosArray(gate);
	}
}
void GateList::setNumGates(int num) { numGates = num; }
int GateList::getNumGates(void) { return numGates; }
void GateList::setPosArray(LogicGate gate) { posArray[gate.getGateID()] = gate; }
LogicGate* GateList::getPosArray(void) { return posArray; }
