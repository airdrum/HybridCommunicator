/*
 * Sensor.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */

#include "Sensor.h"
#include <iostream>

	Sensor::Sensor(){
	init();
}

	Sensor::~Sensor(){

}

void Sensor::init(){
	std::cout << "Sensor has been called" << std::endl;
}


void Sensor::getWindData()
{

}
void Sensor::getSolarRadiation()
{

}
void Sensor::getUv()
{

}
void Sensor::getTemperature()
{

}

void Sensor::getHumidity()
{

}
