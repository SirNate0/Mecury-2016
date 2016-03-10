/*
 * Servo.hpp
 *
 *  Created on: Jan 20, 2016
 *      Author: nathan
 */

#pragma once

#include "wiringPi/wiringPiI2C.h"
#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
//#ifdef __cplusplus
//extern "C" {
//#endif
////these return standard linux filehandles (fd)
//extern int wiringPiI2CRead           (int fd) ;
//extern int wiringPiI2CReadReg8       (int fd, int reg) ;
//extern int wiringPiI2CReadReg16      (int fd, int reg) ;
//
//extern int wiringPiI2CWrite          (int fd, int data) ;
//extern int wiringPiI2CWriteReg8      (int fd, int reg, int data) ;
//extern int wiringPiI2CWriteReg16     (int fd, int reg, int data) ;
//
//extern int wiringPiI2CSetupInterface (const char *device, int devId) ;
//extern int wiringPiI2CSetup          (const int devId) ;
//
//#ifdef __cplusplus
//}
//#endif

class Setup
{

};

#include "I2C.hpp"

class Servo
{
public:
	Servo(): value(0)
	{
		wiringFD = wiringPiI2CSetup(targetAddress);
		if (wiringFD == -1)
		{
			printf("ERROR!!!\n\n\n");
		}
	}
	void Set(float v)
	{
		Set((signed char) (v * 127));
	}
	void Set(int i)
	{
		Set((signed char)i);
	}
	void Set(signed char v)
	{
		value = v;
//		wiringPiI2CWrite(wiringFD, value);
////		wiringPiI2CWriteReg8(wiringFD, 2, v);
//		printf("I Set Servo: %d\n", v);
//		unsigned char test[2] ={0};
		int test = v;//0x0f0f0fff;
		int fd,e;
		int dID = 0x0c;
		// data to be sent
//		test[0]=0x01;
//		test[1]=0xff;

		if((fd=wiringPiI2CSetup(dID))==-1)
		printf("error opening i2c channel\n\r");

		if((e= wiringPiI2CWrite(fd,test))==-1){
		printf("error writing to slave %x EC: %d\n\r", dID, errno);
		}else{

		printf("writing hex:0x%i size:%i\n\r",test,sizeof(test));
		}
//		sleep(1);
//		value = v;
//		I2C::Write(0x0c,v);
	}
	signed char Get() const
	{
		return value;
	}

	void Update()
	{

	}

//	signed char value;
	int value;
	static const int targetAddress = 4;//2;
	int wiringFD;

	enum Servos
	{
		ArmOpen = 1,
		ClawOpen = 2,
		TriggerOpen = 3,
		ArmClose = 11,
		ClawClose = 12,
		TriggerClose = 13,
		//Phone = 100 // plus angle 0-360, divided by 4
		PhoneRight = 4,
		PhoneLeft = 14,
		PhoneStop = 24
	};

	void SetServo(int ServoToSet)
	{
		I2C::Write('S',(signed char)(ServoToSet));//joystick >> 24);
	}

};


