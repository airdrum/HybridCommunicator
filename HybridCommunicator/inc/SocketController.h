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
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <linux/if_ether.h>
#include <stdint.h>

#define UDP_HDR_SIZE 8
#define INET_HDR_LEN 5

#define MAX_PSEUDO_PKT_SIZE 1484
#define MAX_DATA_SIZE 1484
#define SA struct sockaddr

#include "Tests.h"
#include "Nodes.h"

using namespace std;
// For little endian
struct pseudo_iphdr
{
	uint32_t source_addr;
	uint32_t dest_addr;
	uint8_t zeros;
	uint8_t prot;
	uint16_t length;
};


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
	Tests m_test;
	uint16_t checksum(uint8_t *data, unsigned int size);
	int m_raw_sock_fso;
	int m_raw_sock_rf;
	struct timespec ts;
	uint8_t m_send_data[MAX_DATA_SIZE];
	//unsigned int packet_size;
	unsigned int m_send_data_size;
	double m_start_time;
	double m_end_time;
	struct sockaddr_in m_src_addr_rf;
	struct sockaddr_in m_dst_addr_rf;

	struct sockaddr_in m_src_addr_fso;
	struct sockaddr_in m_dst_addr_fso;


	void init();
public:
	SocketController();
	~SocketController();
	void createSocketData(vector<Nodes> _node_list, Tests _test);

	// TCP/IP packet related functions
	unsigned int build_udp_packet(struct sockaddr_in src_addr, struct sockaddr_in dst_addr, uint8_t *udp_packet, uint8_t *data, unsigned int data_size);
	unsigned int build_ip_packet(struct in_addr src_addr, struct in_addr dst_addr, uint8_t protocol, uint8_t *ip_packet, uint8_t *data, unsigned int data_size);
	void send_udp_packet(int raw_sock, struct sockaddr_in src_addr, struct sockaddr_in dst_addr, uint8_t *data, unsigned int data_size);

	// send single data
	void sendSingleData(char* dummyPacket);

};



#endif /* SOCKETCONTROLLER_H_ */
