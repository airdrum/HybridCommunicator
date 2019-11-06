//============================================================================
// Name        : HybridCommunicator.cpp
// Author      : Samet Yildiz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Communicator.h"
#include <chrono>
#include <ctime>
using namespace std;


int main() {
	auto start = std::chrono::system_clock::now();
	    // Some computation here
	    auto end = std::chrono::system_clock::now();

	    std::chrono::duration<double> elapsed_seconds = end-start;
	    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	    std::cout << "finished computation at " << std::ctime(&end_time)
	              << "elapsed time: " << elapsed_seconds.count() << "s\n";
	Communicator *pCommunicator = new Communicator();
	pCommunicator->start();
	return 0;
}
