/*
 * PacketGenerator.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef PACKETGENERATOR_H_
#define PACKETGENERATOR_H_
#define DUMMY_PACKET_SIZE 1450
#include <iostream>

class PacketGenerator
{
	void init();

public:
	PacketGenerator();
	~PacketGenerator();

	void generateDummyPacket(char* packet);
	char generateJpgPacket();
	char generateVideoPacket();
};




#endif /* PACKETGENERATOR_H_ */
