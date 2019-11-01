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


vector<Tests> TestConfigLoader::getConfigData()
{
	_test.testNumber = m_test_number++;
	m_tests_list.push_back(_test);
	_test.testNumber = m_test_number++;
	m_tests_list.push_back(_test);
	return m_tests_list;

}



