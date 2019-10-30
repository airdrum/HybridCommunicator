/*
 * Logger.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <iostream>

class Logger
{
	void init();
public:
	Logger();
	~Logger();
	void printTransmitData();
	void printReceiveData();

	void printTransmitDataRate();
	void printReceiveDataRate();

	void printErrorRate();

};



#endif /* LOGGER_H_ */
