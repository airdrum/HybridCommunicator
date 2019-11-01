
#ifndef TESTS_H_
#define TESTS_H_

#include <string>
#include <iostream>
using namespace std;

struct Tests{
	int testNumber;
	string transmissionType;
	string direction;
	string protocol;
	int bufferSize;
	int duration;
	int timeout;
};

#endif /* TESTS_H_ */
