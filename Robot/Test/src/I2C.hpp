/*
 * I2C.hpp
 *
 *  Created on: Feb 13, 2016
 *      Author: nathan
 */

#pragma once

#include <map>

class I2C
{
public:

	enum Device{Sensors = 2, Servos = 3, Motors = 4};

	static void Write(Device d, float f);
	static void Write(Device d, int i);
	static void Write(Device d, char c);
	static void Write(Device d, const char* bytes, unsigned count);

	static float ReadFloat(Device d);
	static int ReadInt(Device d);
	static char ReadByte(Device d);
//	static unsigned ReadBytes(Device d, char* bytes);

private:
	static std::map<Device, int> fds;
	static int error;
	I2C();
	virtual ~I2C();
};

