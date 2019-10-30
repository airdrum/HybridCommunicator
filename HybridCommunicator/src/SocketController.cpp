/*
 * SocketController.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */


#include "SocketController.h"
#include <iostream>

SocketController::SocketController(){
	init();
}

SocketController::~SocketController(){

}

void SocketController::init(){
	std::cout << "SocketController::init() is called" << std::endl;
}

void SocketController::createSocketData()
{
	std::cout << "SocketController::createSocketData() is called" << std::endl;
}

void SocketController::sendSingleData(string protocol)
{
	if(protocol=="tcp")
	{
		m_tcp.generateData();
	}
	else if (protocol == "udp")
	{
		m_udp.generateData();
	}
}

