/*
 * PacketCoder.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

/*
 * SocketController.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */


#include "PacketCoder.h"

PacketCoder::PacketCoder(){
	init();
}

PacketCoder::~PacketCoder(){

}

void PacketCoder::init(){
	std::cout << "PacketCoder has been called" << std::endl;
}

void PacketCoder::encodeData(char* data)
{
	m_encoder.encodeData(data);
}
void PacketCoder::decodeData()
{
	m_decoder.decodeData();
}




