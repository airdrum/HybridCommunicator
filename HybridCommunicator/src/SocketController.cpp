/*
 * SocketController.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */


#include "SocketController.h"
#include <iostream>
#define DEBUG 0

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
		for(int i = 0; i<_node_list.size();i++){
			if(_node_list[i].nodeName == "EngineeringNode")
				return i;
		}
	}else if (m_test_direction == "BusToEng"){
		for(int i = 0; i<_node_list.size();i++){
			if(_node_list[i].nodeName == "BusinessNode")
				return i;
		}
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

int readContent(){
	int sum = 0;
	int x;
	ifstream inFile;

	inFile.open("config/file.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	while (inFile >> x) {
		sum = sum + x;
	}

	inFile.close();
	return sum;
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

	if(_test.transmissionType.compare("FSO")==0){
		printf("[+] FSO socket is activated...\n");
		if((m_raw_sock_fso = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			perror("socket");
			exit(1);
		}
	}else if(_test.transmissionType.compare("RF")==0){
		printf("[+] RF socket is activated...\n");
		if((m_raw_sock_rf = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			perror("socket");
			exit(1);
		}
	}else if(_test.transmissionType.compare("RFFSO")==0){
		printf("[+] RFFSO socket is activated...\n");
		if((m_raw_sock_fso = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			perror("socket");
			exit(1);
		}

		if((m_raw_sock_rf = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			perror("socket");
			exit(1);
		}
	}else if(_test.transmissionType.compare("Hard-RFFSO")==0){
		printf("[+] RFFSO socket is activated...\n");
		if((m_raw_sock_fso = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			perror("socket");
			exit(1);
		}

		if((m_raw_sock_rf = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			perror("socket");
			exit(1);
		}
	}


}

void SocketController::createSocketData( vector<Nodes> _node_list, Tests _test)
{
	m_test = _test;
	setTransmissionInformation(_node_list,m_test);

#ifndef DEBUG

	std::cout << "####################################################################" << std::endl;
	std::cout << "----TEST INFORMATION for TEST-" <<m_test.testNumber << "---------" << std::endl;
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
#endif


	if(m_test.transmissionType.compare("RF") == 0){


		m_src_addr_rf.sin_family = AF_INET;
		m_src_addr_rf.sin_port = htons(6000);
		inet_aton(m_sender_rf_ip.c_str(), &m_src_addr_rf.sin_addr);

		m_dst_addr_rf.sin_family = AF_INET;
		m_dst_addr_rf.sin_port = htons(6001);
		inet_aton(m_receiver_rf_ip.c_str(), &m_dst_addr_rf.sin_addr);
	}else if(m_test.transmissionType.compare("FSO") == 0){

		m_src_addr_fso.sin_family = AF_INET;
		m_src_addr_fso.sin_port = htons(5000);
		inet_aton(m_sender_fso_ip.c_str(), &m_src_addr_fso.sin_addr);

		m_dst_addr_fso.sin_family = AF_INET;
		m_dst_addr_fso.sin_port = htons(5001);
		inet_aton(m_receiver_fso_ip.c_str(), &m_dst_addr_fso.sin_addr);
	}else if(m_test.transmissionType.compare("RFFSO") == 0){
		m_src_addr_fso.sin_family = AF_INET;
		m_src_addr_fso.sin_port = htons(5000);
		inet_aton(m_sender_fso_ip.c_str(), &m_src_addr_fso.sin_addr);

		m_dst_addr_fso.sin_family = AF_INET;
		m_dst_addr_fso.sin_port = htons(5001);
		inet_aton(m_receiver_fso_ip.c_str(), &m_dst_addr_fso.sin_addr);
		m_src_addr_rf.sin_family = AF_INET;
		m_src_addr_rf.sin_port = htons(6000);
		inet_aton(m_sender_rf_ip.c_str(), &m_src_addr_rf.sin_addr);

		m_dst_addr_rf.sin_family = AF_INET;
		m_dst_addr_rf.sin_port = htons(6001);
		inet_aton(m_receiver_rf_ip.c_str(), &m_dst_addr_rf.sin_addr);
	}else if(m_test.transmissionType.compare("Hard-RFFSO") == 0){
		m_src_addr_fso.sin_family = AF_INET;
		m_src_addr_fso.sin_port = htons(5000);
		inet_aton(m_sender_fso_ip.c_str(), &m_src_addr_fso.sin_addr);

		m_dst_addr_fso.sin_family = AF_INET;
		m_dst_addr_fso.sin_port = htons(5001);
		inet_aton(m_receiver_fso_ip.c_str(), &m_dst_addr_fso.sin_addr);
		m_src_addr_rf.sin_family = AF_INET;
		m_src_addr_rf.sin_port = htons(6000);
		inet_aton(m_sender_rf_ip.c_str(), &m_src_addr_rf.sin_addr);

		m_dst_addr_rf.sin_family = AF_INET;
		m_dst_addr_rf.sin_port = htons(6001);
		inet_aton(m_receiver_rf_ip.c_str(), &m_dst_addr_rf.sin_addr);
	}



	timespec_get(&ts, TIME_UTC);
	m_start_time = ts.tv_sec;
	//return data;
}



void SocketController::sendSingleData(char* dummyPacket)
{
	if(m_protocol.compare("TCP") == 0)
	{
		std::cout << "TCP packet transmission will be handled later" << std::endl;
	}
	else if (m_protocol.compare("UDP") == 0)
	{

		string line;
		ifstream myfile ("config/file.txt");





		strcpy((char *)m_send_data, dummyPacket);
		m_send_data_size = strlen(dummyPacket);
		int i =0;
		do {
			timespec_get(&ts, TIME_UTC);
			m_end_time = ts.tv_sec;
			if(m_test.transmissionType.compare("RF") == 0){
				send_udp_packet(m_raw_sock_rf, m_src_addr_rf, m_dst_addr_rf, m_send_data, m_send_data_size);
				usleep(3000 * 1);
			}else if(m_test.transmissionType.compare("FSO") == 0){
				send_udp_packet(m_raw_sock_fso, m_src_addr_fso, m_dst_addr_fso, m_send_data, m_send_data_size);
				usleep(300 * 1);
			}else if(m_test.transmissionType.compare("RFFSO") == 0){
				send_udp_packet(m_raw_sock_rf, m_src_addr_rf, m_dst_addr_rf, m_send_data, m_send_data_size);
				send_udp_packet(m_raw_sock_fso, m_src_addr_fso, m_dst_addr_fso, m_send_data, m_send_data_size);
			}else if(m_test.transmissionType.compare("Hard-RFFSO") == 0){
				//cout << readContent()<<endl;
				if(readContent()== 1){
					send_udp_packet(m_raw_sock_rf, m_src_addr_rf, m_dst_addr_rf, m_send_data, m_send_data_size);
					usleep(3000 * 1);

				}else if(readContent()== 2){
					send_udp_packet(m_raw_sock_fso, m_src_addr_fso, m_dst_addr_fso, m_send_data, m_send_data_size);
					usleep(300 * 1);
				}
			}
			i++;

		}while((m_end_time - m_start_time) < (double)m_test.duration);
	}
}




uint16_t SocketController::checksum(uint8_t *data, unsigned int size)
{
	int i;
	int sum = 0;
	uint16_t *p = (uint16_t *)data;

	for(i = 0; i < size; i += 2){
		sum += *(p++);
	}

	uint16_t carry = sum >> 16;
	uint16_t tmp = 0x0000ffff & sum;
	uint16_t res = ~(tmp + carry);

	return res;
}


unsigned int SocketController::build_ip_packet(struct in_addr src_addr, struct in_addr dst_addr, uint8_t protocol, uint8_t *ip_packet, uint8_t *data, unsigned int data_size)
{
	struct iphdr *ip_header;

	ip_header = (struct iphdr *)ip_packet;
	ip_header->version = 4;
	ip_header->ihl = INET_HDR_LEN;
	ip_header->tos = 0;
	ip_header->tot_len = htons(INET_HDR_LEN * 4 + data_size);
	ip_header->id = 0; // Filled in automatically
	ip_header->frag_off = 0;
	ip_header->ttl = 64;
	ip_header->protocol = protocol;
	ip_header->check = 0; // Filled in automatically
	ip_header->saddr = src_addr.s_addr;
	ip_header->daddr = dst_addr.s_addr;

	memcpy(ip_packet + sizeof(struct iphdr), data, data_size);

	return sizeof(struct iphdr) + data_size;
}



unsigned int SocketController::build_udp_packet(struct sockaddr_in src_addr, struct sockaddr_in dst_addr, uint8_t *udp_packet, uint8_t *data, unsigned int data_size)
{
	uint8_t pseudo_packet[MAX_PSEUDO_PKT_SIZE];
	uint16_t length;
	struct udphdr *udph;
	struct pseudo_iphdr *p_iphdr = (struct pseudo_iphdr *)pseudo_packet;

	length = UDP_HDR_SIZE + data_size;
	udph = (struct udphdr *)udp_packet;
	udph->source = src_addr.sin_port;
	udph->dest = dst_addr.sin_port;
	udph->len = htons(length);
	memcpy(udp_packet + UDP_HDR_SIZE, data, data_size);

	if(length + sizeof(struct pseudo_iphdr) > MAX_PSEUDO_PKT_SIZE){
		fprintf(stderr, "Buffer size not enough");
		exit(1);
	}

	// Calculate checksum with pseudo ip header
	p_iphdr->source_addr = src_addr.sin_addr.s_addr;
	p_iphdr->dest_addr = dst_addr.sin_addr.s_addr;
	p_iphdr->zeros = 0;
	p_iphdr->prot = IPPROTO_UDP; //udp
	p_iphdr->length = udph->len;

	// Do NOT use udph->len instead of length.
	// udph->len is in big endian
	memcpy(pseudo_packet + sizeof(struct pseudo_iphdr), udph, length);
	udph->check = checksum(pseudo_packet, sizeof(struct pseudo_iphdr) + length);

	return length;
}


void SocketController::send_udp_packet(int raw_sock, struct sockaddr_in src_addr, struct sockaddr_in dst_addr, uint8_t *data, unsigned int data_size)
{

	unsigned int packet_size;
	unsigned int ip_payload_size;
	uint8_t packet[ETH_DATA_LEN];

	memset(packet, 0, ETH_DATA_LEN);
	ip_payload_size = build_udp_packet(src_addr, dst_addr, packet + sizeof(struct iphdr), data, data_size);

	packet_size = build_ip_packet(src_addr.sin_addr, dst_addr.sin_addr, IPPROTO_UDP, packet, packet + sizeof(struct iphdr), ip_payload_size);

	if(sendto(raw_sock, packet, packet_size, 0, (struct sockaddr *)&dst_addr, sizeof(dst_addr)) < 0){
		perror("sendto");
		exit(1);
	}

}
