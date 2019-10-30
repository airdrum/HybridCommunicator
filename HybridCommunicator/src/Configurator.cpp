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

void Configurator::getNodes()
{
	m_node_config.getConfigData();
}
void Configurator::getTests()
{
	m_test_config.getConfigData();
}
void Configurator::setConfigurations()
{
	this->getNodes();
	this->getTests();
}


