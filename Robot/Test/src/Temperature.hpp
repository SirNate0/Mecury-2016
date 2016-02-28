/*
 * Temperature.hpp
 *
 *  Created on: Feb 17, 2016
 *      Author: nathan
 */

#pragma once

#include "I2C.hpp"
#include <unistd.h>

using namespace std;

struct Temperature
{
	static void Print()
	{
		for (int i = 1; i < 6; ++i)
		{
			I2C::Write('T',(signed char) i);
//			float f;
//			read(I2C::fds['T'],&f, 4);
//			close(I2C::fds['T']);
//			I2C::fds.erase(I2C::fds.find('T'));
//			printf("Temperature Byte: %d\n",I2C::ReadByte('T'));

			I2C::Device d = 'T';
			std::map<I2C::Device, int>::iterator it = I2C::fds.find(d);
			int fd, e;
			if(it != I2C::fds.end())
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
					I2C::fds[d] = fd;
			}
			float f;
			read(fd,&f,sizeof(f));
			printf("Temp: %f\n",f);
		}
	}
};
