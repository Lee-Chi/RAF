#pragma once

#include "Socket.h"

using namespace raf::kernel;

class MockSocket: public Socket
{
public:
	MockSocket(){}
	~MockSocket(){}

	bool connect(const string& ip, int port) {return true;}
	bool disconnect() {return true;}
	bool send(const string& buffer) {return true;}
	bool recv(string& buffer) {return true;}
};