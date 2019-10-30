/*
 * Configurator.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <iostream>

class Configurator
{
	void init();
public:
	Configurator();
	~Configurator();
	void getNodes();
	void getTests();
	void setConfigurations();
};



#endif /* CONFIGURATOR_H_ */
