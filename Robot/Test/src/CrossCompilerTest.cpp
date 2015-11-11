//============================================================================
// Name        : CrossCompilerTest.cpp
// Author      : Nathan Lydick
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "kNet.h"
#include "kNet/DebugMemoryLeakCheck.h"

#include "kNet/Clock.h"

using namespace kNet;

enum STATUS
{
	GOOD, WAITING, CONNECTED, LOST_CONNECTION, CLOSED_CONNECTION
};
STATUS status;


bool timedOut()
{
	return false;
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

#ifndef RASPI
#include <SDL2/SDL.h>
#include "DisplayJoystick.hpp"
#endif

int main()
{
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
#endif

	while (true)
	{
		server->Process();
#ifndef RASPI
		SDL_Event e;
		SDL_PollEvent(&e);
		disp.Display(joy);
#endif
		if (status == WAITING)
		{
			sleep(100);
			cout << "Waiting for connection..." << endl;
			continue;
		}
		if (status == GOOD && timedOut() == false)
		{
#ifndef RASPI
//			disp.Display(joy);
#endif
		}
		else
		{
			status = LOST_CONNECTION;
		}
		if (status == LOST_CONNECTION)
		{
			displayError();
			sleep(100);
			continue;
		}
		if (status == CLOSED_CONNECTION)
			break;
//		sleep(100);

	}
	return 0;
}