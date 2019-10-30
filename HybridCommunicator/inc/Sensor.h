/*
 * Sensor.h
 *
 *  Created on: Oct 28, 2019
 *      Author: sy
 */

#ifndef SENSOR_H_
#define SENSOR_H_


class Sensor
{
	void init();
public:
	Sensor();
	~Sensor();
	void getWindData();
	void getTemperature();
	void getHumidity();
	void getSolarRadiation();
	void getUv();
};



#endif /* SOCKET_H_ */

