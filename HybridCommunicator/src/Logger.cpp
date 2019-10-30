/*
 * Logger.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */



#include "Logger.h"

Logger::Logger(){
	init();
}

Logger::~Logger(){

}

void Logger::init(){
	std::cout << "Logger has been called" << std::endl;

}

void Logger::printTransmitData()
{

}
void Logger::printReceiveData()
{

}

void Logger::printTransmitDataRate()
{

}
void Logger::printReceiveDataRate()
{
	std::cout << "Logger::printReceiveDataRate()" << std::endl;

}

void Logger::printErrorRate()
{
	std::cout << "Logger::printErrorRate()" << std::endl;

}
