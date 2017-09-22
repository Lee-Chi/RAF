#pragma once

#include <string>
	using std::string;

namespace raf{ namespace kernel{

class Socket
{
public:
	Socket(){}
	virtual ~Socket(){}
	virtual bool initialize(const string& ip, int port) = 0;
	virtual bool finalize() = 0;
	virtual bool sendMessage(const string& message) = 0;
	virtual bool receiveMessage(string& message) = 0;
};

}}