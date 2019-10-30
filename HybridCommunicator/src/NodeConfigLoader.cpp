/*
 * NodeConfigLoader.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: sy
 */


/*
 * TestConfigLoader.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: sy
 */


/*
 * Socket.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */


#include "NodeConfigLoader.h"
#include <iostream>

NodeConfigLoader::NodeConfigLoader(){
	init();
}

NodeConfigLoader::~NodeConfigLoader(){

}

void NodeConfigLoader::init(){
	std::cout << "TestConfigLoader has been called" << std::endl;
}


void NodeConfigLoader::getConfigData()
{
	std::cout << "Node cofig xml is received." << std::endl;
}





