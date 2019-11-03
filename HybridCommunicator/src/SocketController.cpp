/*
 * SocketController.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */


#include "SocketController.h"
#include <iostream>
#define DEBUG 1
SocketController::SocketController(){
	init();
}

SocketController::~SocketController(){

}

void SocketController::init(){
	std::cout << "SocketController::init() is called" << std::endl;
}


int SocketController::getSenderIndex( vector<Nodes> _node_list,Tests _test)
{
	m_test_direction = _test.direction;
	int sender_index;

	if (m_test_direction == "EngToBus"){
		for(int i = 0; i<_node_list.size();i++)
			if(_node_list[i].nodeName == "EngineeringNode")
				return i;
	}else if (m_test_direction == "BusToEng"){
		for(int i = 0; i<_node_list.size();i++)
			if(_node_list[i].nodeName == "BusinessNode")
				return i;
	}
	return 0;

}

int SocketController::getReceiverIndex( vector<Nodes> _node_list,Tests _test)
{
	m_test_direction = _test.direction;

	if (m_test_direction == "EngToBus"){
		for(int i = 0; i<_node_list.size();i++){
			if(_node_list[i].nodeName == "BusinessNode")
				return i;
		}
	}else if (m_test_direction == "BusToEng"){
		for(int i = 0; i<_node_list.size();i++)
			if(_node_list[i].nodeName == "EngineeringNode")
				return i;
	}
	return 0;

}

void SocketController::setTransmissionInformation( vector<Nodes> _node_list,Tests _test)
{
	int sender_index , receiver_index;
	sender_index = getSenderIndex(_node_list, _test);
	receiver_index = getReceiverIndex(_node_list, _test);
	m_protocol = _test.protocol;


	m_sender_office_ip = _node_list[sender_index].officeIpAddres;
	m_sender_office_username = _node_list[sender_index].officeUserName;
	m_sender_office_password = _node_list[sender_index].officePassword;
	m_sender_fso_ip = _node_list[sender_index].fsoIpAddress;
	m_sender_fso_dutIp = _node_list[sender_index].fsoDutIpAddress;
	m_sender_fso_username = _node_list[sender_index].fsoUserName;
	m_sender_fso_password = _node_list[sender_index].fsoPassword;
	m_sender_rf_ip = _node_list[sender_index].rfIpAddress;
	m_sender_rf_dutIp = _node_list[sender_index].rfDutIpAddress;
	m_sender_rf_username = _node_list[sender_index].rfUsername;
	m_sender_rf_password = _node_list[sender_index].rfPassword;


	m_receiver_office_ip = _node_list[receiver_index].officeIpAddres;
	m_receiver_office_username = _node_list[receiver_index].officeUserName;
	m_receiver_office_password = _node_list[receiver_index].officePassword;
	m_receiver_fso_ip = _node_list[receiver_index].fsoIpAddress;
	m_receiver_fso_dutIp = _node_list[receiver_index].fsoDutIpAddress;
	m_receiver_fso_username = _node_list[receiver_index].fsoUserName;
	m_receiver_fso_password = _node_list[receiver_index].fsoPassword;
	m_receiver_rf_ip = _node_list[receiver_index].rfIpAddress;
	m_receiver_rf_dutIp = _node_list[receiver_index].rfDutIpAddress;
	m_receiver_rf_username = _node_list[receiver_index].rfUsername;
	m_receiver_rf_password = _node_list[receiver_index].rfPassword;


}

void SocketController::createSocketData(uint8_t* dummyPacket, vector<Nodes> _node_list, Tests _test)
{

	setTransmissionInformation(_node_list,_test);
	if(DEBUG){

		std::cout << "####################################################################" << std::endl;
		std::cout << "----TEST INFORMATION for TEST-" <<_test.testNumber << "---------" << std::endl;
		std::cout << "Protocol: " << m_protocol << std::endl;
		std::cout << "*****SENDER*****" << std::endl;
		std::cout << "Sender Office   ip      : " << m_sender_office_ip<< std::endl;
		std::cout << "Sender Office   username: " << m_sender_office_username << std::endl;
		std::cout << "Sender Office   password: " <<m_sender_office_password << std::endl;
		std::cout << "Sender          fsoip   : " <<m_sender_fso_ip << std::endl;
		std::cout << "Sender          fsodutip: " << m_sender_fso_dutIp<< std::endl;
		std::cout << "Sender          fsouname: " << m_sender_fso_username << std::endl;
		std::cout << "Sender          fso_pswd: " << m_sender_fso_password << std::endl;
		std::cout << "Sender          rfip    : " << m_sender_rf_ip<< std::endl;
		std::cout << "Sender          rfdutip : " << m_sender_rf_dutIp << std::endl;
		std::cout << "Sender          rf_uname: " << m_sender_rf_username << std::endl;
		std::cout << "Sender          rf_pswd : " << m_sender_rf_password << std::endl;
		std::cout << "*****RECEIVER*****" << std::endl;
		std::cout << "Receiver Office ip      : " << m_receiver_office_ip<< std::endl;
		std::cout << "Receiver Office username: " << m_receiver_office_username << std::endl;
		std::cout << "Receiver Office password: " <<m_receiver_office_password << std::endl;
		std::cout << "Receiver        fsoip   : " <<m_receiver_fso_ip << std::endl;
		std::cout << "Receiver        fsodutip: " << m_receiver_fso_dutIp<< std::endl;
		std::cout << "Receiver        fsouname: " << m_receiver_fso_username << std::endl;
		std::cout << "Receiver        fso_pswd: " << m_receiver_fso_password << std::endl;
		std::cout << "Receiver        rfip    : " << m_receiver_rf_ip<< std::endl;
		std::cout << "Receiver        rfdutip : " << m_receiver_rf_dutIp << std::endl;
		std::cout << "Receiver        rf_uname: " << m_receiver_rf_username << std::endl;
		std::cout << "Receiver        rf_pswd : " << m_receiver_rf_password << std::endl;
		std::cout << "####################################################################" << std::endl;
		std::cout << std::endl;
	}

}

void SocketController::sendSingleData()
{
	if(m_protocol=="tcp")
	{
		m_tcp.generateData();
	}
	else if (m_protocol == "udp")
	{
		m_udp.generateData();
	}
}

