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

char PacketGenerator::generateDummyPacket()
{
	std::cout << "PacketGenerator::generateDummyPacket() is called" << std::endl;
	return 'g';
}
char PacketGenerator::generateJpgPacket()
{
	return 'g';
}
char PacketGenerator::generateVideoPacket()
{
	return 'g';
}
