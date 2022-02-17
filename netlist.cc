#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "gates.h"
#include "netlist.h"
#define SCALE_FACTOR 100
#define NUM_GATES 42

using namespace std;

//global variables
LogicGate gate; 
GateList gateList;
NetList netList; 

Net::Net(void) {}
void Net::setStartGate(int value) { startGate = value; }
void Net::setEndGate(int value) { endGate = value; }
int Net::getStartGate(void) { return startGate; }
int Net::getEndGate(void) { return endGate; }

NetList::NetList(void) {}
void NetList::readInNetList() {
	ifstream inputFile("netlist.txt", ios::in);

	int a, b;
	int counter = 0;
	Net net;

	while (inputFile >> a >> b) {
		net.setStartGate(a);
		net.setEndGate(b);
		netlist[counter] = net;
		counter++;
	}
}
void NetList::printGateLocations() {
	for (int i = 0; i < 42; i++) {
		cout << "Gate: " << i << " Pos: " << gateList.getPosArray()[i].getGatePos() << endl;
	}
	/*int testID;
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 42; j++) {
			testID = gateList.getPosArray()[j].getGateID();
			if (testID == i) {
				cout << "Gate: " << i << " Pos: " << j << endl;
				break;
			}
		}

	}*/
}
void NetList::greedyPlacement() {
	int lenBefore, lenAfter, id1, id2, gatePos1, gatePos2;
	for (int i = 0; i < NUM_GATES * SCALE_FACTOR; i++) {
		lenBefore = calcNetLength();

		id1 = rand() % 42;
		id2 = rand() % 42;

		gatePos1 = gateList.getPosArray()[id1].getGatePos();
		gatePos2 = gateList.getPosArray()[id2].getGatePos();
		gateList.getPosArray()[id1].setGatePos(gatePos2); //gatePos1 = gatePos2
		gateList.getPosArray()[id2].setGatePos(gatePos1); //gatePos2 = gatePos1

		lenAfter = calcNetLength();

		if (lenAfter > lenBefore) {
			gatePos1 = gateList.getPosArray()[id1].getGatePos();
			gatePos2 = gateList.getPosArray()[id2].getGatePos();
			gateList.getPosArray()[id1].setGatePos(gatePos2); //gatePos1 = gatePos2
			gateList.getPosArray()[id2].setGatePos(gatePos1); //gatePos2 = gatePos1
		}
	}
}
int NetList::calcNetLength() {
	int length = 0;

	for (int i = 0; i < 100; i++) {
		int startGateID = netlist[i].getStartGate();
		int endGateID = netlist[i].getEndGate();

		int startGatePos = gateList.getPosArray()[startGateID].getGatePos();
		int endGatePos = gateList.getPosArray()[endGateID].getGatePos();

		length += abs(startGatePos - endGatePos);
	}

	return length;
}
void NetList::SA_Algorithm()
{
	float prob;
	float throwDice;
	int pos1;
	int pos2;
	int lengthBeforeSwap;
	int lengthAfterSwap;
	int numGates = NUM_GATES;
	int gatePos1, gatePos2;
	//this is a linear ramping down of temperature
	//see if you can find a better annealing schedule!
	for (float temp = 150.0; temp >= 0; temp -= 1)
	{
		for (int i = 0; i < numGates * SCALE_FACTOR; i++)
		{
			pos1 = rand() % numGates;
			pos2 = rand() % numGates;
			lengthBeforeSwap = calcNetLength();
			
			//swapping gates
			gatePos1 = gateList.getPosArray()[pos1].getGatePos();
			gatePos2 = gateList.getPosArray()[pos2].getGatePos();
			gateList.getPosArray()[pos1].setGatePos(gatePos2); //gatePos1 = gatePos2
			gateList.getPosArray()[pos2].setGatePos(gatePos1); //gatePos2 = gatePos1

			lengthAfterSwap = calcNetLength(); //calculate length before
			if (lengthAfterSwap <= lengthBeforeSwap) //always accept good swap
				prob = 1.0;
			else //if a bad swap you still may still accept based on Boltzmann probability
				prob = exp(-((float)lengthAfterSwap - lengthBeforeSwap) / (0.5 * temp));
			throwDice = static_cast<float>(rand()) / RAND_MAX;
			if (throwDice > prob) {
				//reject the swap and swap back
				gatePos1 = gateList.getPosArray()[pos1].getGatePos();
				gatePos2 = gateList.getPosArray()[pos2].getGatePos();
				gateList.getPosArray()[pos1].setGatePos(gatePos2); //gatePos1 = gatePos2
				gateList.getPosArray()[pos2].setGatePos(gatePos1); //gatePos2 = gatePos1
			}
		}//inner for loop
	} //end temperature sweep loop
}// end of member function