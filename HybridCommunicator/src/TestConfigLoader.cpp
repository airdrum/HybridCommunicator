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


#include "TestConfigLoader.h"
#include <iostream>

TestConfigLoader::TestConfigLoader(){
	init();
}

TestConfigLoader::~TestConfigLoader(){

}

void TestConfigLoader::init(){
	std::cout << "TestConfigLoader has been called" << std::endl;
}


void TestConfigLoader::getConfigData()
{
	std::cout << "Test cofig xml is received." << std::endl;

}



