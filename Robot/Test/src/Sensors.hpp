/*
 * Sensors.hpp
 *
 *  Created on: Feb 10, 2016
 *      Author: nathan
 */

#pragma once

class Sensors
{
public:
	struct Data
	{
		float l, r, b;
	};
	Sensors();
	~Sensors();
	void Read();


	//	signed char value;
	int value;
	static const int targetAddress = 2;
	int wiringFD;
	Data data;
};

