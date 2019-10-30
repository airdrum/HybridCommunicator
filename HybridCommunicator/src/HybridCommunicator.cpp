//============================================================================
// Name        : HybridCommunicator.cpp
// Author      : Samet Yildiz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Communicator.h"
using namespace std;


int main() {
	Communicator *pCommunicator = new Communicator();
	pCommunicator->start();
	return 0;
}
