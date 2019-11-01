/*
 * Decoder.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */



#include "Decoder.h"
#include <iostream>

Decoder::Decoder(){
	init();
}

Decoder::~Decoder(){

}

void Decoder::init(){
	std::cout << "Decoder has been called" << std::endl;
}


void Decoder::decodeData()
{
	std::cout << "--> Decoder data has been generated." << std::endl;
}


