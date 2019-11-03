/*
 * SocketController.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef SOCKETCONTROLLER_H_
#define SOCKETCONTROLLER_H_
#include <iostream>
#include <string>
#include "Socket.h"
#include "Sensor.h"
#include "Udp.h"
#include "Tcp.h"
#include <vector>
#include "Tests.h"
#include "Nodes.h"

using namespace std;
class SocketController
{
	int getSenderIndex( vector<Nodes> _node_list, Tests _test);
	int getReceiverIndex( vector<Nodes> _node_list, Tests _test);
	void setTransmissionInformation( vector<Nodes> _node_list,Tests _test);
	Socket m_socket;
	Sensor m_sensor;
	Tcp m_tcp;
	Udp m_udp;
	string m_test_direction;
	string m_protocol;
	string m_sender_name;
	string m_sender_office_ip;
	string m_sender_office_username;
	string m_sender_office_password;
	string m_sender_fso_ip;
	string m_sender_fso_dutIp;
	string m_sender_fso_username;
	string m_sender_fso_password;
	string m_sender_rf_ip;
	string m_sender_rf_dutIp;
	string m_sender_rf_username;
	string m_sender_rf_password;

	string m_receiver_name;
	string m_receiver_office_ip;
	string m_receiver_office_username;
	string m_receiver_office_password;
	string m_receiver_fso_ip;
	string m_receiver_fso_dutIp;
	string m_receiver_fso_username;
	string m_receiver_fso_password;
	string m_receiver_rf_ip;
	string m_receiver_rf_dutIp;
	string m_receiver_rf_username;
	string m_receiver_rf_password;
	void init();
public:
	SocketController();
	~SocketController();
	void createSocketData(uint8_t* dummyPacket, vector<Nodes> _node_list, Tests _test);

	void sendSingleData();

};



#endif /* SOCKETCONTROLLER_H_ */
