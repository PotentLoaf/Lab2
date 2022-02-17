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