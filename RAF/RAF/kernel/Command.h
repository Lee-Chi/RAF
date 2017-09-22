#pragma once

#include <string>
using std::string;

namespace raf{ namespace kernel{

enum Status
{
	WAIT = -1,
	SUCCESS = 0,
	FAIL 
};

class Receiver
{
public:
	Receiver(){}
	virtual ~Receiver(){}
	virtual bool execute() = 0;
};

class Command
{
public:
	Command();
	Command(Receiver* r);
	virtual ~Command();
	
	virtual void execute();

	Status getStatus() const;

protected:
	void setStatus(Status s);
private:
	Status status;
	Receiver* receiver;
};

}}