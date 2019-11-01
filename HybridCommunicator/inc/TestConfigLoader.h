


#ifndef TESTCONFIGLOADER_H_
#define TESTCONFIGLOADER_H_
#include "Tests.h"
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
using namespace std;
class TestConfigLoader
{
	vector<Tests> m_tests_list;
	int m_test_number = 1;
	void init();
public:
	TestConfigLoader();
	~TestConfigLoader();
	vector<Tests> getConfigData();
};

#endif /* NODECONFIGLOADER_H_ */
