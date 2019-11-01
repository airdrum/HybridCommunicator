


#ifndef TESTCONFIGLOADER_H_
#define TESTCONFIGLOADER_H_
#include "Tests.h"
#include <vector>
using namespace std;
class TestConfigLoader
{
	vector<Tests> m_tests_list;
	Tests _test;
	int m_test_number = 1;
	void init();
public:
	TestConfigLoader();
	~TestConfigLoader();
	vector<Tests> getConfigData();
};

#endif /* NODECONFIGLOADER_H_ */
