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

#include "Servo.hpp"

float clamp(float v, float min, float max)
{
    return (v <= min) ? min : ((v >= max) ? max : v);
}

class Drive
{
    public:
        void setTankSpeed(float left, float right)
        {
            leftMotor.set(left);//
            rightMotor.set(right);
        }
        void setArcadeSpeed(float forward, float turn)
        {
            //need a motor class....right?
//            leftMotor.set(left) "tank"
//            rightMotor.set(right);
//            or
            leftMotor.set(clamp(forward + turn,-1.0,1.0)); "arcade"
            rightMotor.set(clamp(forward - turn,-1.0,1.0));
            
        
        
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
        Servo leftMotor;
        Servo rightMotor;
        float gas;
        float status;
        
    
}

#endif /* DRIVE_HPP */

