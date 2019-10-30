/*
 * SocketController.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef SOCKETCONTROLLER_H_
#define SOCKETCONTROLLER_H_
#include <iostream>
#include "Socket.h"
#include "Sensor.h"

class SocketController
{
	Socket *m_socket;
	Sensor *m_sensor;
	void init();
public:
	SocketController();
	~SocketController();
	void createSocketData();
	void setSenderPort();
	void setReceiverPort();
};



#endif /* SOCKETCONTROLLER_H_ */
