/*
 * NodeConfigLoader.cpp
 *
 *  Created on: Oct 30, 2019
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


vector<Nodes> NodeConfigLoader::getConfigData()
{


	// populate tree structure pt
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("config/NodeConfig.xml", pt);


	BOOST_FOREACH( ptree::value_type const& v, pt.get_child("Nodes") ) {
		Nodes _node;
		if( v.first == "Node" ) {
			//_node.officeIpAddres = v.second.get<std::string>("carrier");


			// Office interface for the node xml tag
			_node.nodeName 		 = v.second.get<std::string>("Name");
			_node.officeIpAddres = v.second.get<std::string>("Office.ipAddress");
			_node.officeUserName = v.second.get<std::string>("Office.username");
			_node.officePassword = v.second.get<std::string>("Office.password");

			// FSO interface information for the node xml tag
			_node.fsoIpAddress = v.second.get<std::string>("FSO.ipAddress");
			_node.fsoUserName = v.second.get<std::string>("FSO.username");
			_node.fsoPassword = v.second.get<std::string>("FSO.password");
			_node.fsoDutIpAddress = v.second.get<std::string>("FSO.dutIp");

			// RF interface information for the node xml tag
			_node.rfIpAddress = v.second.get<std::string>("RF.ipAddress");
			_node.rfUsername = v.second.get<std::string>("RF.username");
			_node.rfPassword = v.second.get<std::string>("RF.password");
			_node.rfDutIpAddress = v.second.get<std::string>("RF.dutIp");
			m_nodes_list.push_back(_node);
		}
	}

	return m_nodes_list;
}





