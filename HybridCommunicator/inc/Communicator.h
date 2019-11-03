/*
 * Communicator.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef COMMUNICATOR_H_
#define COMMUNICATOR_H_
#include "PacketCoder.h"
#include "PacketGenerator.h"
#include "SocketController.h"
#include "Logger.h"
#include "Configurator.h"

class Communicator
{
private:
	void init();
	PacketGenerator m_pktGen;
	SocketController m_socket;
	PacketCoder m_pktCoder;
	Configurator m_config;
	Logger m_logger;
	uint8_t m_dummyPacket[DUMMY_PACKET_SIZE];
	vector<Nodes> m_node_list;
	vector<Tests> m_test_list;

public:
	Communicator();
	void start();
	~Communicator();

};



#endif /* COMMUNICATOR_H_ */
