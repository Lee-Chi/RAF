#include "Command.h"

using namespace raf::kernel;

class MockReceiverTrue: public Receiver
{
public:
	MockReceiverTrue(){}
	virtual ~MockReceiverTrue(){}

	bool execute()
	{
		return true;
	}
};

class MockReceiverFalse: public Receiver
{
public:
	MockReceiverFalse(){}
	virtual ~MockReceiverFalse(){}

	bool execute()
	{
		return false;
	}
};