/*
 * Encoder.h
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <iostream>

class Encoder
{

	void init();
public:
	Encoder();
	~Encoder();
	void encodeData(char* data);
};






#endif /* ENCODER_H_ */
