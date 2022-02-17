#ifndef NETLIST_H
#define NETLIST_H

#include "gates.h"
#define SCALE_FACTOR 100
#define NUM_NETS 100

class Net
{
public:
	Net();
	void setStartGate(int value);
	void setEndGate(int value);
	int getStartGate();
	int getEndGate();
private:
	int startGate;
	int endGate;
};
class NetList
{
public:
	NetList();
	void readInNetList();
	void printGateLocations();
	void greedyPlacement();
	int calcNetLength();
	void SA_Algorithm();
	
	//you might want other member functions!
private:
	Net netlist[NUM_NETS];
	GateList gatelayout;
	int numNets;

}; 

#endif