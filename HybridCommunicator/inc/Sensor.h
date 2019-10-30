


#ifndef SENSOR_H_
#define SENSOR_H_


class Sensor
{
	void init();
public:
	Sensor();
	~Sensor();
	void getWindData();
	void getSolarRadiation();
	void getUv();
	void getTemperature();
	void getHumidity();
};



#endif /* SOCKET_H_ */
