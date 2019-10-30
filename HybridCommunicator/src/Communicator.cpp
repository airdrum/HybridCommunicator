/*
 * Communicator.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#include "Communicator.h"

Communicator::Communicator(){


	init();
}

Communicator::~Communicator(){

}

void Communicator::init(){
	std::cout << "Communicator Facade has been called." << std::endl;

	m_pktGen = new PacketGenerator();
	m_socket = new	SocketController();
	m_pktCoder = new PacketCoder();
	m_config = new Configurator();
	m_logger = new Logger();



}

void Communicator::start(){
	// Get node information from NodeConfig.xml
	m_config->getNodes();
	// Get test configuration information from TestConfig.xml
	m_config->getTests();
	// Generate a dummy Packet
	m_pktGen->generateDummyPacket();
	// Encode the generated Data
	m_pktCoder->encodeData();
	// Set the receiver protocol port
	m_socket->setReceiverPort();
	// Set the Sender protocol port
	m_socket->setSenderPort();
	// Create socket data
	m_socket->createSocketData();
	// Decode received data
	m_pktCoder->decodeData();
	// Print error rate
	m_logger->printErrorRate();
	// Print receive data rate
	m_logger->printReceiveDataRate();
}


