/*
 * Configurator.h
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <iostream>
#include "TestConfigLoader.h"
#include "NodeConfigLoader.h"
class Configurator
{
	void init();
	TestConfigLoader m_test_config;
	NodeConfigLoader m_node_config;
public:
	Configurator();
	~Configurator();
	void getNodes();
	void getTests();
	void setConfigurations();
};



#endif /* CONFIGURATOR_H_ */
