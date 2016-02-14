/*
 * I2C.cpp
 *
 *  Created on: Feb 13, 2016
 *      Author: nathan
 */

#include "I2C.hpp"

#include <errno.h>

I2C::I2C()
{
	// TODO Auto-generated constructor stub

}

I2C::~I2C()
{
	// TODO Auto-generated destructor stub
}

void I2C::Write(Device d, float f)
{
	int data = reinterpret_cast<int>(f);
	for (unsigned int i = 0; i < sizeof(data); ++i)
	{
		Write(d, char((data & (0xff << i)) >> i));
	}
}
void I2C::Write(Device d, int i)
{
	for (unsigned int i = 0; i < sizeof(i); ++i)
	{
		Write(d, char((i & (0xff << i)) >> i));
	}
}
void I2C::Write(Device d, char c)
{
		auto it = fds.find(d);
		int fd, e;
		if(it != fds.end())
		{
		   //element found;
		   fd = it->second;
		}
		else
		{
			fd = wiringPiI2CSetup(d);
			if (fd == -1)
				printf("error opening i2c channel\n\r");
			else
				fds[d] = fd;
		}



		if((e= wiringPiI2CWrite(fd,c))==-1)
		{
			printf("error writing to slave EC: %d\n\r", errno);
		}
//		else
//		{
//			printf("writing hex:0x%i size:%i\n\r",c,sizeof(c));
//		}
}
void I2C::Write(Device d, const char* bytes, unsigned count)
{
	for (unsigned i = 0; i < count; ++i)
	{
		Write(d, bytes[i]);
	}
}

float I2C::ReadFloat(Device d)
{
	float data;
	char v;
	unsigned char* bytes = (unsigned char*) &data;

	for (unsigned int i = 0; i < sizeof(data); ++i)
	{
		v=ReadByte(d);
		bytes[i] = v;// & 0xff;
	}
	return data;
}
int I2C::ReadInt(Device d)
{
	int data;
	char v;
	unsigned char* bytes = (unsigned char*) &data;

	for (unsigned int i = 0; i < sizeof(data); ++i)
	{
		v=ReadByte(d);
		bytes[i] = v;// & 0xff;
	}
	return data;
}
char I2C::ReadByte(Device d)
{
	auto it = fds.find(d);
	int fd, e;
	if(it != fds.end())
	{
	   //element found;
	   fd = it->second;
	}
	else
	{
		fd = wiringPiI2CSetup(d);
		if (fd == -1)
			printf("error opening i2c channel\n\r");
		else
			fds[d] = fd;
	}

//	char data;
//	int v = 0;
//	unsigned char* d = (unsigned char*) &data;
//
//	for (unsigned int i = 0; i < sizeof(data); ++i)
//	{
		return wiringPiI2CRead(fd);
//		d[i] = v & 0xff;
//	}
//
//	printf("Read sensor data: %f %f %f", data.l, data.r, data.b);
}

//unsigned I2C::ReadBytes(Device d, char* bytes)
//{
//}
