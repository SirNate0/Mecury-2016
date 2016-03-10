/*
 * Sensors.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: nathan
 */

#include "I2C.hpp"

#include "wiringPi/wiringPiI2C.h"
#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

#include "Sensors.hpp"

Sensors::Sensors()
{
	// TODO Auto-generated constructor stub
	data.l = 7.0f;
	data.r = 8.0f;
	data.b = 0.000077;

}

Sensors::~Sensors()
{
	// TODO Auto-generated destructor stub
}

void Sensors::Read()
{
//
////	value = v;
////		wiringPiI2CWrite(wiringFD, value);
//////		wiringPiI2CWriteReg8(wiringFD, 2, v);
////		printf("I Set Servo: %d\n", v);
////		unsigned char test[2] ={0};
//
//	const int requestData = 0;//0x0f0f0fff;
//	int fd,e;
//	const int dID = 0x2;
//	// data to be sent
////		test[0]=0x01;
////		test[1]=0xff;
//
//	if((fd=wiringPiI2CSetup(dID))==-1)
//	printf("error opening i2c channel\n\r");
//
//	if((e= wiringPiI2CWrite(fd,requestData))==-1){
//	printf("error writing to slave EC: %d\n\r", errno);
//	}else{
//
//	printf("writing hex:0x%i size:%i\n\r",requestData,sizeof(requestData));
//	}
//	int v = 0;
//	unsigned char* d = (unsigned char*) &data;
//
//	for (unsigned int i = 0; i < sizeof(Sensors::Data); ++i)
//	{
//		v=wiringPiI2CRead(fd);
//		d[i] = v & 0xff;
//	}

	I2C::Device d = 'S';
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
	read(fd,&data,sizeof(data));

//	printf("Read sensor data: %f %f %f\n", data.l, data.r, data.b);
//		sleep(1);
}


