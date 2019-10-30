/*
 * Udp.h
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */

#ifndef UDP_H_
#define UDP_H_


class Udp
{
	int m_rx_port;
	int m_tx_port;
	int m_pkt_len;
	void init();
public:
	Udp();
	~Udp();
	void setSenderPort();
	void setReceiverPort();
	void setPacketLength();
	void setBufferSize();
	void generateData();
};



#endif /* SOCKET_H_ */

