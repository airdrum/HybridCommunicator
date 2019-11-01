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
	// populate tree structure pt
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("config/TestConfig.xml", pt);

	BOOST_FOREACH( ptree::value_type const& v, pt.get_child("Tests") ) {
		Tests _test;
		if( v.first == "Test" ) {
			//_node.officeIpAddres = v.second.get<std::string>("carrier");


			// Office interface for the node xml tag
			_test.testNumber	 = m_test_number++;
			_test.transmissionType = v.second.get<std::string>("TransmissionType");
			_test.direction = v.second.get<std::string>("Direction");
			_test.protocol = v.second.get<std::string>("Protocol");
			_test.bufferSize= stoi(v.second.get<std::string>("BufferSize"));
			_test.duration = stoi(v.second.get<std::string>("Duration"));
			_test.timeout = stoi(v.second.get<std::string>("Timeout"));

			m_tests_list.push_back(_test);
		}
	}

	return m_tests_list;

}



