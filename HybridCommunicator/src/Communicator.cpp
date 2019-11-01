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


}

void Communicator::start(){
	// Get all nodes information from NodeConfig.xml
	m_node_list = m_config.getNodes();
	// Get all tests information from NodeConfig.xml
	m_test_list = m_config.getTests();
	// Generate a dummy Packet
	m_pktGen.generateDummyPacket();
	// Encode the generated Data
	m_pktCoder.encodeData();
	// Create socket data
	m_socket.createSocketData();
	// Send Single Data
	m_socket.sendSingleData("udp");
	// Decode received data
	m_pktCoder.decodeData();
	// Print error rate
	m_logger.printErrorRate();
	// Print receive data rate
	m_logger.printReceiveDataRate();
}


