/*
 * Communicator.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#include "Communicator.h"

Communicator::Communicator(){
	std::cout << "#### Communicator Facade has been called." << std::endl;
	m_pktGen = new PacketGenerator();
	m_socket = new	SocketController();
	m_pktCoder = new PacketCoder();
	m_config = new Configurator();
	m_logger = new Logger();

	init();
}

Communicator::~Communicator(){

}

void Communicator::init(){

	m_config->getNodes();
	m_config->getTests();
	m_pktGen->generateDummyPacket();
	m_pktCoder->encodeData();
	m_socket->setReceiverPort();
	m_socket->setSenderPort();
	m_socket->createSocketData();
	m_pktCoder->decodeData();
	m_logger->printErrorRate();
	m_logger->printReceiveDataRate();


}



