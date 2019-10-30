


#ifndef SOCKET_H_
#define SOCKET_H_


class Socket
{
	void init();
public:
	Socket();
	~Socket();
	void makeUdpData();
	void makeTcpData();
	void generateCrc();
	void calculateChecksum();
};



#endif /* SOCKET_H_ */
