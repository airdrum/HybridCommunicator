/*
 * PacketGenerator.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef PACKETGENERATOR_H_
#define PACKETGENERATOR_H_
#include <iostream>

class PacketGenerator
{
	void init();
public:
	PacketGenerator();
	~PacketGenerator();

	char generateDummyPacket();
	char generateJpgPacket();
	char generateVideoPacket();
};




#endif /* PACKETGENERATOR_H_ */
