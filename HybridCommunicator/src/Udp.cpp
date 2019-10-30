/*
 * Udp.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */


/*
 * Tcp.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */




#include "Udp.h"
#include <iostream>

Udp::Udp(){
	init();
}

Udp::~Udp(){

}

void Udp::init(){
	std::cout << "Udp has been called" << std::endl;
}


void Udp::generateData()
{
	std::cout << "--> Udp data has been generated." << std::endl;
}

void Udp::setSenderPort()
{

}
void Udp::setReceiverPort()
{

}
void Udp::setPacketLength()
{

}
void Udp::setBufferSize()
{

}




