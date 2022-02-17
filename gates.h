#ifndef gates_h
#define gates_h

class LogicGate {
public:
	void setGateID(int loc);
	int getGateID(void);
	void setGatePos(int loc);
	int getGatePos(void);
	LogicGate();
private:
	int gateID;
	int gatePos;
};

class GateList {
public:
	void setNumGates(int num);
	int getNumGates(void);
	void setPosArray(LogicGate gate);
	LogicGate* getPosArray(void);
	GateList();
private:
	int numGates;
	LogicGate posArray[42];
};

#endif