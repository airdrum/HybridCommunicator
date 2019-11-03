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
	// Get all tests information from TestConfig.xml
	m_test_list = m_config.getTests();
	// Generate a dummy Packet
	for(Tests _test : m_test_list){
		std::cout << "Test No#			:" <<_test.testNumber << std::endl;
		std::cout << "Direction			:" <<_test.direction << std::endl;
		std::cout << "Transmission type :" <<_test.transmissionType << std::endl;
		std::cout << "Protocol			:" <<_test.protocol << std::endl;
		std::cout << "Duration			:" <<_test.duration << std::endl;
		std::cout << "Buffer size		:" <<_test.bufferSize << std::endl;

		m_pktGen.generateDummyPacket(m_dummyPacket);
		// Encode the generated Data
		m_pktCoder.encodeData(m_dummyPacket);
		// Create socket data
		m_socket.createSocketData(m_dummyPacket,m_node_list,_test);
		// Send Single Data
		m_socket.sendSingleData();
		// Decode received data
		m_pktCoder.decodeData();
		// Print error rate
		m_logger.printErrorRate();
		// Print receive data rate
		m_logger.printReceiveDataRate();
		std::cout << "**************************" << std::endl;
	}//system.pick bekleme, clock nasıl kullanılır, işşlemci load mikltarı ölçülür

}


