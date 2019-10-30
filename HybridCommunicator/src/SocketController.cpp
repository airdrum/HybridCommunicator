/*
 * SocketController.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */


#include "SocketController.h"
#include <iostream>

SocketController::SocketController(){
	m_socket = new Socket();
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
void SocketController::setSenderPort()
{
	std::cout << "SocketController::setSenderPort() is called" << std::endl;
}
void SocketController::setReceiverPort()
{
	std::cout << "SocketController::setReceiverPort() is called" << std::endl;
}

