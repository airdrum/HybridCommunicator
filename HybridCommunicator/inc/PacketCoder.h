/*
 * PacketCoder.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef PACKETCODER_H_
#define PACKETCODER_H_

#include <iostream>
#include "Encoder.h"
#include "Decoder.h"

class PacketCoder
{
	Encoder m_encoder;
	Decoder m_decoder;
	void init();
public:
	PacketCoder();
	~PacketCoder();

	void encodeData();
	void decodeData();

};


#endif /* PACKETCODER_H_ */
