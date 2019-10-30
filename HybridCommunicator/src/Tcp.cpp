/*
 * Tcp.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */




#include "Tcp.h"
#include <iostream>

Tcp::Tcp(){
	init();
}

Tcp::~Tcp(){

}

void Tcp::init(){
	std::cout << "Tcp has been called" << std::endl;
}


void Tcp::generateData()
{
	std::cout << "--> Tcp data has been generated." << std::endl;
}


void Tcp::setSenderPort()
{

}
void Tcp::setReceiverPort()
{

}
void Tcp::setPacketLength()
{

}
void Tcp::setBufferSize()
{

}



