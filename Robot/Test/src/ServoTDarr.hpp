/*
 * Servo.hpp
 *
 *  Created on: Jan 20, 2016
 *      Author: nathan
 */

#pragma once

//#include <WiringPiI2C.h>
#ifdef __cplusplus
extern "C" {
#endif
//these return standard linux filehandles (fd)
extern int wiringPiI2CRead           (int fd) ;
extern int wiringPiI2CReadReg8       (int fd, int reg) ;
extern int wiringPiI2CReadReg16      (int fd, int reg) ;

extern int wiringPiI2CWrite          (int fd, int data) ;
extern int wiringPiI2CWriteReg8      (int fd, int reg, int data) ;
extern int wiringPiI2CWriteReg16     (int fd, int reg, int data) ;

extern int wiringPiI2CSetupInterface (const char *device, int devId) ;
extern int wiringPiI2CSetup          (const int devId) ;

#ifdef __cplusplus
}
#endif

class Setup
{

};

class Servo
{
public:
	Servo(): value(0)
	{
		wiringFD = wiringPiI2CSetup(targetAddress);
		if (wiringFD == -1)
		{
			printf("ERROR!!!");
		}
	}
	void set(float v)
	{
		set((signed char) (v * 127));
	}
	void set(signed char v)
	{
		value = v;
		wiringPiI2CWrite(wiringFD, value);
	}
	signed char get() const
	{
		return value;
	}

	void update()
	{

	}

//	signed char value;
	int value;
	static const int targetAddress = 2;
	int wiringFD;

};


