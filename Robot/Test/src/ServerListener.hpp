/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerListener.hpp
 * Author: Tyler
 *
 * Created on January 22, 2016, 4:42 PM
 */

#ifndef SERVERLISTENER_HPP
#define SERVERLISTENER_HPP

class ServerListener
{
    public:
        float getStatus()
        {
            return status;
        }
        
private:
    float buttonPress;
    float status;
    
}

#endif /* SERVERLISTENER_HPP */

