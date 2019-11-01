


#ifndef NODECONFIGLOADER_H_
#define NODECONFIGLOADER_H_

#include "Nodes.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <vector>
using namespace std;
namespace pt = boost::property_tree;

class NodeConfigLoader
{
	vector<Nodes> m_nodes_list;

	pt::ptree xml_tree;
	void init();
public:
	NodeConfigLoader();
	~NodeConfigLoader();
	vector<Nodes> getConfigData();
};



#endif /* NODECONFIGLOADER_H_ */
