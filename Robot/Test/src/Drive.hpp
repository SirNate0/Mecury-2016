/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SrerverListener.hpp
 * Author: Tyler
 *
 * Created on January 22, 2016, 4:32 PM
 */

#ifndef DRIVE_HPP
#define DRIVE_HPP

#include "I2C.hpp"
#include "wiringPi/wiringPiI2C.h"
#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

float clamp(float v, float min, float max)
{
    return (v <= min) ? min : ((v >= max) ? max : v);
}
signed char clamp(signed char v, signed char min, signed char max)
{
    return (v <= min) ? min : ((v >= max) ? max : v);
}

class Motor
{
//	void set(flaot val)
//	{
//		set(val * )
//	}
public:
	void set(float joystick)
	{
		I2C::Write('M',(signed char)(joystick * 127));//joystick >> 24);
	}

};

class Drive
{
    public:
        void setTankSpeed(float left, float right)
        {
//            leftMotor.set(left);//
//            rightMotor.set(right);
        	char drive[2] = {(signed char)(left * 20), (signed char)(right * 20)};
        	I2C::Write('M',drive, 2);//joystick >> 24);
            printf("\nDriving %f %f\n", left, right);
        }
        void setArcadeSpeed(float forward, float turn)
        {
            //need a motor class....right?
//            leftMotor.set(left) "tank"
//            rightMotor.set(right);
//            or
//            leftMotor.set(clamp(forward + turn,-1.0,1.0)); "arcade"
//            rightMotor.set(clamp(forward - turn,-1.0,1.0));
//        	char drive[2] = {forward, turn};
//        	I2C::Write('M',drive, 2);//joystick >> 24);
        }
        
        void turbo()
        {
            //motor class?
            
        }
        
        void stop()
        {
//            leftMotor.Set(0);
//            rightMotor.Set(0);
        }
    
    private:
//        Motor leftMotor;
        Motor rightMotor;
        float gas;
        float status;
        
    
};

#endif /* DRIVE_HPP */

