/*
 * PacketGenerator.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */
#include "PacketGenerator.h"
#include <iostream>

PacketGenerator::PacketGenerator(){
	init();
}

PacketGenerator::~PacketGenerator(){

}

void PacketGenerator::init(){
	std::cout << "PacketGenerator::init() is called" << std::endl;

}

void PacketGenerator::generateDummyPacket(char* packet )
{

	for (int r = 0; r<DUMMY_PACKET_SIZE; r++)
		packet[r] = rand() % ('z' - 'a' + 1) + 'a';

}
char PacketGenerator::generateJpgPacket()
{
	return 'g';
}
char PacketGenerator::generateVideoPacket()
{
	return 'g';
}
