/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Catapult.hpp
 * Author: Tyler
 *
 * Created on January 20, 2016, 7:35 PM
 */

#ifndef CATAPULT_HPP
#define CATAPULT_HPP

#include "Servo.hpp"

class Catapult {
public:
    Catapult();
    virtual ~Catapult();
    void Launch(bool fire);
    
    void Fire()
    {
            ServoTrigger.Set(-127); //extreme value, extreme retraction in this case
            Reset();
            fired = true;
    }
//
    void  Reset()
    {
            ServoReset.Set(-127);
            ServoTrigger.Set(127);
    }
//
//    void moveXAxis(float xInput)
//    {
//            xArmMotor.set(xInput);
//    }
//
//    void moveYAxis(float yInput)
//    {
//            yArmMotor.set(yInput)
//    {

    bool HasFired()
    {
            return fired;
    }
    
private:
    bool fire;
    bool fired;
    Servo ServoReset;
    Servo ServoTrigger;
};

#endif /* CATAPULT_HPP */
