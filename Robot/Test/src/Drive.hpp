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
#include <math.h>

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

#define PI (3.14159265358979323846)
#define PI_OVER_2 (3.14159265358979323846 / 2.0)
#define PI_OVER_4 (3.14159265358979323846 / 4.0)
#define threshold PI_OVER_4
        float getLeftArcade(float theta)
        {
            if (theta < -PI + threshold)
                return 0.0;
            else if (theta < -PI_OVER_2)
                return -((theta + PI_OVER_2 + threshold) / (PI_OVER_2 - threshold));
            else if (theta < -threshold)
                return -1.0;
            else if (theta < threshold)
                return 0.0;
            else if (theta < PI_OVER_2)
                return 1.0;
            else if (theta < PI-threshold)
                return - ((theta - PI_OVER_2 - threshold) / (PI_OVER_2 - threshold));
            else
                return 0.0;
        }
        float getRightArcade(float theta)
        {
            if (theta < -PI + threshold)
                return 0.0;
            else if (theta < -PI_OVER_2)
                return -1.0;
            else if (theta < -threshold)
                return ((theta + threshold) / (PI_OVER_2 - threshold));
            else if (theta < threshold)
                return 0.0;
            else if (theta < PI_OVER_2)
                return ((theta - threshold) / (PI_OVER_2 - threshold));
            else if (theta < PI-threshold)
                return 1.0;
            else
                return 0.0;
        }

        void setArcadeSpeed(float forward, float turn)
        {
        	float l=forward;
			float r=forward;
			float theta = atan2(forward,turn);
			float radius = sqrt(forward*forward + turn*turn);
			printf("%f %f | %f %f (f,t | theta r)\n",l,turn,theta,radius);
			//bending theta towards y axis messes up the later part
//			if (theta > 0)
////				if (theta <= PI)
//				theta = (theta - PI_OVER_2) / 4.0 + PI_OVER_2;
//			else
//				theta = (theta + PI_OVER_2) / 4.0 - PI_OVER_2;
//			l += turn;
//			r -= turn;
			if ((theta < threshold && theta > -threshold) || theta > PI - threshold || theta < -PI + threshold || radius < 0.05)
				l = r = 0;
			else
			{
				l = radius*getLeftArcade(theta);//sin(theta - PI_OVER_2);
				r = radius*getRightArcade(theta);//cos(theta - PI_OVER_2);
			}
			setTankSpeed(l,r);

//			if (turn >= 0)
//			{
//				if (forward >= 0)
//				{
//
//				}
//			}


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

