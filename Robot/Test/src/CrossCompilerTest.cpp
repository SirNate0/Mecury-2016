//============================================================================
// Name        : CrossCompilerTest.cpp
// Author      : Nathan Lydick
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "wiringPi/wiringPi.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;
#include "kNet.h"
#include "kNet/DebugMemoryLeakCheck.h"

#include "kNet/Clock.h"

#include "Servo.hpp"
#include "Sensors.hpp"
#include "Temperature.hpp"
#include "Drive.hpp"

using namespace kNet;

enum STATUS
{
	GOOD, WAITING, CONNECTED, LOST_CONNECTION, CLOSED_CONNECTION
};
STATUS status;

bool received = false;
static const unsigned int TIMEOUT = 1000;//milliseconds
int millisSinceLastPacket = 0;
int lastMillis = millis();

static const unsigned long SENSORMESSAGE = 0x77;


bool timedOut()
{
	return (millisSinceLastPacket > TIMEOUT);
}

void displayError()
{

}

void sleep(int millis)
{
	Clock::Sleep(millis);
}

#include "Joystick.hpp"

//struct Joystick
//{
//	short x, y, x2, y2, l, r;
//	static const int BUTTONS = 11;
//	unsigned char buttons[BUTTONS];
//	void Print()
//	{
//		printf("(%d, %d), (%d, %d) [%d | %d]\n", x, y, x2, y2, l, r);
//		for (int i = 0; i < BUTTONS; i++)
//			if (buttons[i])
//				printf("%d:@ ", i);
//			else
//				printf("%d:  ", i);
////			printf("A%s") todo: use proper labels for the buttons
//		printf("\n");
//
//	}
////	void PrintFancy()
////	{
////		/*  x######			    ######X
////		 *     X				   X
////		 * (######,  X		 X		 X
////		 *    X          X		   X   X
////		 *  ######)        (######,	 X
////		 *		------		  X
////		 *		------	    ######)
////		 */
////	}
//};

Joystick joy;

class JoyPrinter: public IMessageHandler
{
public:
	/// Called whenever the network stack has received a message that the application
	/// needs to process.
	/// @param source The kNet connection this message originates from.
	/// @param packetId A unique incrementing id counter that identifies the number of the UDP packet this message originated from. Use this
	///     to prune out-of-order messages if necessary. kNet automatically discards duplicate messages, and can do out-of-order discarding
	///     automatically as well, if you use message content ID's. Otherwise, you can use the packetId to do the pruning manually.
	/// @param messageId Contains the id (or the "type") of the message. This is the one you specified when sending the message
	/// @param data Points to the raw data buffer. This buffer may be zero if numBytes == 0.
	/// @param numBytes The length of the raw data buffer, in bytes.
	virtual void HandleMessage(MessageConnection *source, packet_id_t packetId,
			message_id_t messageId, const char *data, size_t numBytes)
	{
		if (numBytes >= sizeof(Joystick))
		{
			joy = *((Joystick*) data);
			joy.Print();
			status = GOOD;
			received = true;
		}

//		if (Clock::SecondsSinceF(source->lastHeardTime) > TIMEOUT)
//			status = LOST_CONNECTION;
	}

};

// This object gets called for notifications on new network connection events.
class ServerListener: public INetworkServerListener
{
	JoyPrinter jp;
	int count;
public:
	ServerListener() :
			count(0)
	{
	}
	virtual ~ServerListener()
	{
	}
	void NewConnectionEstablished(MessageConnection *connection)
	{
//		const int maxMsgBytes = 256;
//		// Start building a new message.
//		NetworkMessage *msg = connection->StartNewMessage(cHelloMessageID, maxMsgBytes);
//		msg->reliable = true;
//
//		// Create a DataSerializer object with a buffer of 256 bytes.
//		DataSerializer ds(msg->data, maxMsgBytes);
//		// Add a message string.
//		ds.AddString(std::string("Hello! You are connecting from ") + connection->RemoteEndPoint().ToString());
//		// Push the message out to the client.
//		connection->EndAndQueueMessage(msg, ds.BytesFilled());
		connection->RegisterInboundMessageHandler(&jp);
		LOG(LogUser, "Client connected from %s.",
				connection->ToString().c_str());
//		count++;
//		if (count>100)
//
	}

	void ClientDisconnected(MessageConnection *connection)
	{
		connection->Disconnect();
		status = CLOSED_CONNECTION;
	}
};
#define RASPI
#ifndef RASPI
#include <SDL2/SDL.h>
#include "DisplayJoystick.hpp"
#endif


void StopEverything(Servo& s, Drive& d)
{
	s.SetServo(Servo::PhoneStop);
	d.setTankSpeed(0.0,0.0);
}

//void Order66()
//{
//	StopEverything();
//}

//controls:
/*
 * view - triggers (or other joystick?)
 * bumpers + face button = catapult
 * 2 buttons to open/close the claw
 * buttons/axis for the arm
 * steering
 */

int main()
{
	Servo s;
	Sensors sensors;
	Drive d;
	int i = 0;
	StopEverything(s,d);
	status = WAITING;
	kNet::SetLogChannels(LogUser | LogInfo | LogError);

	ServerListener serverListener;
	// Start listening on a port.
	const unsigned short cServerPort = 1234;
	Network network;

	NetworkServer *server = network.StartServer(cServerPort, SocketOverUDP,
			&serverListener, true);

	if (server)
	{
		LOG(LogUser, "Waiting for incoming connections.");
		// Run the main server loop.
		// This never returns since we don't call NetworkServer::Stop(), but for this example, it doesn't matter.
		//		server->RunModalServer();
		server->SetAcceptNewConnections(true);
	}

	EnableMemoryLeakLoggingAtExit();

//			while (connection)
//			{
//				DataSerializer data(sizeof(Joystick));
//				data.Add<Joystick>(j);
//				connection->SendMessage(10,false,false,100,i++,data.GetData(),data.BytesFilled());
//	//					connection->RunModalClient();
//	//			if (i > 1000)
//	//			j.Print();
//				server->Process();
//			}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

#ifndef RASPI
	SDL_Init(SDL_INIT_VIDEO);
	DisplayJoystick disp;
	disp.InitWindow();
#else
//	Servo s; // Moved up for StopEverything
//	Sensors sensors;
//	Drive d;
//	int i = 0;
	//using broadcast instead of send message, so we don't need it
//	NetworkMessage nm;
//	nm.inOrder = false;
//	nm.id = SENSORMESSAGE;
//	nm.reliable = false;
//	nm.Resize(sizeof(sensors.data),true);
//	MessageConnection conn;

	///Wiring pi setup
	/*
	 * test2.c:
	 *      Simple test program to test the wiringPi functions
	 *      PWM test
	 */


//	  int redPWM = 18, green = 23; BCM pins
	  int redPWM = 1, green = 4;

	  printf ("Raspberry Pi wiringPi Setup.n") ;

	  if (wiringPiSetup () == -1)
		  printf("WiringPi failed!!!");


//	  pinMode (redPWM, PWM_OUTPUT) ;
	  pinMode (redPWM, OUTPUT) ;
	  pinMode (green, OUTPUT) ;





#endif



	while (true)
	{
		server->Process();
		printf("time %d\n", millisSinceLastPacket);
#ifndef RASPI
		SDL_Event e;
		if ( SDL_PollEvent(&e) )
		{
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
		}
		disp.Display(joy);
#endif
		if (status == WAITING)
		{
//			pwmWrite(redPWM,250);
			digitalWrite(redPWM,1);
			digitalWrite(green,1);
			lastMillis = millis();
			sleep(100);
			cout << "Waiting for connection..." << endl;
			continue;
		}
		if (status == GOOD)
		{
			if (timedOut() == false)
			{
#ifndef RASPI
//			disp.Display(joy);
#else
	//			pwmWrite(redPWM,0);
				digitalWrite(redPWM,0);
				digitalWrite(green,1);
				if (received)
				{
					millisSinceLastPacket = 0;
					//single servo test
	//				s.Set(joy.y / 36000.0f);
					if (joy.buttons[0])
						s.SetServo(s.ArmClose);
					if (joy.buttons[1])
						s.SetServo(s.ArmOpen);
					if (joy.buttons[2])
						s.SetServo(s.ClawClose);
					if (joy.buttons[3])
						s.SetServo(s.ClawOpen);
					if (joy.l > 0)
						s.SetServo(s.PhoneLeft);
					if (joy.r > 0)
						s.SetServo(s.PhoneRight);
					if ((joy.l < 0 && joy.r < 0) || (joy.l > 0 && joy.r > 0))
						s.SetServo(s.PhoneStop);
					if (joy.buttons[4] &&joy.buttons[5] &&joy.buttons[7] &&joy.buttons[7])
						s.SetServo(s.TriggerOpen);
//					d.setTankSpeed(joy.y / 36000.0f, joy.y2 / 36000.0f);
					d.setArcadeSpeed(joy.y2 / 36000.0f, -joy.x2 / 36000.0f);
				}
				else
				{
					millisSinceLastPacket += millis() - lastMillis;
				}
				received = false;
	//			if (joy.buttons[6])
	//				Temperature::Print();

				if (i % 20 == 0)
				{
					sensors.Read();
					i = 0;
					server->BroadcastMessage(SENSORMESSAGE, false, false, 100,
							0, (char*)&(sensors.data), sizeof(sensors.data));
				}
				i++;

				lastMillis = millis();
				sleep(20);
	#endif
			}
			else
			{
				lastMillis = millis();
				status = LOST_CONNECTION;
			}
		}
		else if (status == LOST_CONNECTION)
		{
			StopEverything(s,d);
			displayError();
			digitalWrite(redPWM,1);
			digitalWrite(green,0);
			if (received)
			{
				status = GOOD;
				millisSinceLastPacket = 0;
				continue;
			}
			lastMillis = millis();
			sleep(100);
		}
		else if (status == CLOSED_CONNECTION)
			break;
//		sleep(100);

	}
	digitalWrite(redPWM,0);
	digitalWrite(green,0);
	StopEverything(s,d);
	return 0;
}
