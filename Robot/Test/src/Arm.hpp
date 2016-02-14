/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arm.hpp
 * Author: Tyler
 *
 * Created on January 21, 2016, 8:52 PM
 */

#ifndef ARM_HPP
#define ARM_HPP

#include "Servo.hpp"

class Arm{
public:
    
    Arm();
    
    void moveXAxis(float armMoveX)
    {
        xArmMotor.set(armMoveX);
    }

    void moveYAxis(float armMoveY)
    {
        yArmMotor.set(armMoveY);
    }
private:
    
    float armMoveX;
    float armMoveY;
    Servo xArmMotor;
    Servo yArmMotor;
}
#endif /* ARM_HPP */

