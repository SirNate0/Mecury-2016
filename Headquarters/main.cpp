/* Copyright The kNet Project.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

/** @file HelloClient.cpp
	@brief */

int status;
static const int GOOD = 0, WAITING = 1, LOST_CONNECTION = 2, CLOSED_CONNECTION = 4;
static const unsigned long SENSORMESSAGE = 0x77;

#include "kNet.h"
#include "kNet/DebugMemoryLeakCheck.h"

#include "kNet/Clock.h"

using namespace kNet;

tick_t lastHeardTick;
static const double TIMEOUT = 1.0;//timeout after 1 second; //TODO: determine what this value should be for competition


// Define a MessageID for our a custom message.
const message_id_t cHelloMessageID = 10;

// This object gets called whenever new data is received.
class MessageListener : public IMessageHandler
{
public:
	void HandleMessage(MessageConnection *source, packet_id_t /*packetId*/, message_id_t messageId, const char *data, size_t numBytes)
   {
      if (messageId == cHelloMessageID)
      {
         // Read what we received.
         DataDeserializer dd(data, numBytes);
         std::cout << "Server says: " << dd.Read<bool>() << std::endl;

         source->Close(0);
      }
   }
};

BottomMemoryAllocator bma;
#include <SDL/SDL.h>
#include <SDL/SDL_joystick.h>

#include "Joystick.hpp"

class JoyPrinter : public IMessageHandler
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
	virtual void HandleMessage(MessageConnection *source, packet_id_t packetId, message_id_t messageId, const char *data, size_t numBytes)
	{
		if (numBytes >= sizeof(Joystick))
		{
			Joystick j = *((Joystick*) data);
			j.Print();
		}

//		if (Clock::SecondsSinceF(source->lastHeardTime) > TIMEOUT)
//			status = LOST_CONNECTION;
	}

};

// This object gets called for notifications on new network connection events.
class ServerListener : public INetworkServerListener
{
	JoyPrinter jp;
	int count;
public:
	ServerListener(): count(0) {}
	virtual ~ServerListener() {}
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
		LOG(LogUser, "Client connected from %s.", connection->ToString().c_str());
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
#include "DisplayJoystick.hpp"

struct Data
{
	float l, r, b, f;
};
class SensorHandler: public IMessageHandler
{
public:
	virtual void HandleMessage(MessageConnection *source, packet_id_t packetId, message_id_t messageId, const char *data, size_t numBytes)
	{
//		if (messageId == SENSORMESSAGE)
			if (numBytes >= sizeof(Data))
			{
				Data d = *((Data*) data);
				LOGUSER("Received sensor data: %f %f %f", d.l, d.r, d.b);
			}

	}

};

int main(int argc, char **argv)
{
	status = WAITING;

	   if (SDL_Init( SDL_INIT_JOYSTICK) < 0)
//		   if (SDL_Init( SDL_INIT_JOYSTICK | SDL_INIT_VIDEO) < 0)
   {
       fprintf(stderr, "Couldn't initialize SDL joystick support: %s\n", SDL_GetError());
       exit(1);
   }

	DisplayJoystick disp;
//	disp.InitWindow();
   printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
   SDL_Joystick* joy = 0;
   SDL_JoystickEventState(SDL_ENABLE);
   Joystick j;
   if (SDL_NumJoysticks() > 0)
   {
	   printf("The names of the joysticks are:\n");
	   joy = SDL_JoystickOpen(0);
	   j.Read(joy);
	   j.Print();
   }

   for(int i=0; i < SDL_NumJoysticks(); i++ )
   {
       printf("    %s\n", SDL_JoystickName(SDL_JoystickOpen(i)));
   }


   printf("\n\n");

//   if (argc < 2)
//      {
//         std::cout << "Usage: " << argv[0] << " server-ip" << std::endl;
//         return 0;
//      }

	kNet::SetLogChannels(LogUser | LogInfo | LogError);

//    ServerListener serverListener;
	// Start listening on a port.
	const unsigned short cServerPort = 4321;//
	   Network network;
	   MessageListener listener;
	   SensorHandler sensors;

//	NetworkServer *server = network.StartServer(cServerPort, SocketOverUDP, &serverListener, true);

//	if (server)
//	{
//		LOG(LogUser, "Waiting for incoming connections.");
//		// Run the main server loop.
//		// This never returns since we don't call NetworkServer::Stop(), but for this example, it doesn't matter.
////		server->RunModalServer();
//		server->SetAcceptNewConnections(true);
//	}

	EnableMemoryLeakLoggingAtExit();


   Ptr(MessageConnection) connection = network.Connect(
//		   "192.168.1.50"
		   argv[1]
				, cServerPort, SocketOverUDP,  &listener);

	if (connection)
	{
		// Run the main client loop.
//		connection->RunModalClient();
		int i = 1;
		LOG(LogUser,"Press the XBox button to quit.");
//		connection->RegisterInboundMessageHandler(&sensors); didn't work

		while (connection)
		{
			DataSerializer data(sizeof(Joystick));
			data.Add<Joystick>(j);
			connection->SendMessage(10,false,false,100,i++,data.GetData(),data.BytesFilled());
//			connection->Process(4);//TODO: register inbound message handler

			NetworkMessage* nm = connection->ReceiveMessage(10);
			if (nm && nm->id == SENSORMESSAGE)
			{
				if (nm->data )// && nm->Size() == sizeof(Data))
				{
					Data d = *((Data *) nm->data);
					LOGUSER("Received sensor data: %f %f %f %f", d.l, d.r, d.b, d.f);
					FILE* f = fopen("out.txt","w");
#define GUI(str) fprintf(f,"%s\n",str)
					GUI("Connected");
#define GUI(str) fprintf(f,"%f\n",str)
					GUI(0.f);
					GUI(d.b);
					GUI(d.r);
					GUI(d.l);
					GUI(d.l);
					GUI(d.l);
					GUI(d.r);
					GUI(d.r);
					fflush(f);
					fclose(f);


				}
			}
			connection->FreeMessage(nm);

//			if (i > 1000)
			if (j.buttons[8])
				connection = 0;

			// event handling
			SDL_Event e;
			if (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
					break;
				else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
					break;
			}
			j.Read(joy);
//			j.Print();

//			j.Print();
//			sleep(1);
			SDL_Delay(50);
//			server->Process();
//			disp.Display(j);
		}
//		connection->
	}

   return 0;
}



/* Server


#include "kNet.h"
#include "kNet/DebugMemoryLeakCheck.h"

using namespace kNet;

// Define a MessageID for our a custom message.
const message_id_t cHelloMessageID = 10;

// This object gets called for notifications on new network connection events.
class ServerListener : public INetworkServerListener
{
public:
	void NewConnectionEstablished(MessageConnection *connection)
	{
		const int maxMsgBytes = 256;
		// Start building a new message.
		NetworkMessage *msg = connection->StartNewMessage(cHelloMessageID, maxMsgBytes);
		msg->reliable = true;

		// Create a DataSerializer object with a buffer of 256 bytes.
		DataSerializer ds(msg->data, maxMsgBytes);
		// Add a message string.
		ds.AddString(std::string("Hello! You are connecting from ") + connection->RemoteEndPoint().ToString());
		// Push the message out to the client.
		connection->EndAndQueueMessage(msg, ds.BytesFilled());
		LOG(LogUser, "Client connected from %s.", connection->ToString().c_str());
	}

	void ClientDisconnected(MessageConnection *connection)
	{
		connection->Disconnect();
	}
};

BottomMemoryAllocator bma;

int main()
{
	EnableMemoryLeakLoggingAtExit();

	Network network;
	ServerListener listener;

	kNet::SetLogChannels(LogUser | LogInfo | LogError);

	LOG(LogUser, "Starting server.");
	// Start listening on a port.
	const unsigned short cServerPort = 1234;
	NetworkServer *server = network.StartServer(cServerPort, SocketOverUDP, &listener, true);

	if (server)
	{
		LOG(LogUser, "Waiting for incoming connections.");
		// Run the main server loop.
		// This never returns since we don't call NetworkServer::Stop(), but for this example, it doesn't matter.
		server->RunModalServer();
	}
}
*/
