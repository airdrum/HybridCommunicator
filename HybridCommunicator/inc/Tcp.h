/*
 * Tcp.h
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */
#ifndef TCP_H_
#define TCP_H_


class Tcp
{
	int m_rx_port;
	int m_tx_port;
	int m_pkt_len;
	void init();
public:
	Tcp();
	~Tcp();
	void setSenderPort();
	void setReceiverPort();
	void setPacketLength();
	void setBufferSize();
	void generateData();
};



#endif /* SOCKET_H_ */
