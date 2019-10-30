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
using namespace std;
class SocketController
{
	Socket m_socket;
	Sensor m_sensor;
	Tcp m_tcp;
	Udp m_udp;

	void init();
public:
	SocketController();
	~SocketController();
	void createSocketData();

	void sendSingleData(string protocol);

};



#endif /* SOCKETCONTROLLER_H_ */
