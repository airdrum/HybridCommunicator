/*
 * Encoder.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */



#include "Encoder.h"
#include <iostream>

Encoder::Encoder(){
	init();
}

Encoder::~Encoder(){

}

void Encoder::init(){
	std::cout << "Encoder has been called" << std::endl;
}


void Encoder::encodeData(uint8_t* data)
{
	std::cout << "No encoding has been provided." << std::endl;
}


