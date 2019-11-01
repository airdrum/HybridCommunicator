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
#include "Tests.h"
#include "Nodes.h"
class Configurator
{
	void init();
	TestConfigLoader m_test_config;
	NodeConfigLoader m_node_config;
	vector<Nodes> m_nodeList;
	vector<Tests> m_testList;
public:
	Configurator();
	~Configurator();
	vector<Nodes> getNodes();
	vector<Tests> getTests();
};



#endif /* CONFIGURATOR_H_ */
