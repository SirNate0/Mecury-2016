/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Claw.hpp
 * Author: Tyler
 *
 * Created on January 22, 2016, 4:46 PM
 */

#ifndef CLAW_HPP
#define CLAW_HPP

class Claw
{
    public:
        Claw()
        {
            
        }
        
        void closeClaw()
        {
            ServoClaw.set(-127);
        }
        
        void openClaw()
        {
            ServoClaw.set(127);
        }

    private:
        Servo ServoClaw;
}

#endif /* CLAW_HPP */

