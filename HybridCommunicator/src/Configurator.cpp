/*
 * Configurator.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: sy
 */

#include "Configurator.h"

Configurator::Configurator(){
	init();
}

Configurator::~Configurator(){

}

void Configurator::init(){

}

vector<Nodes> Configurator::getNodes()
{
	return m_node_config.getConfigData();
}

vector<Tests> Configurator::getTests()
{
	return m_test_config.getConfigData();
}



