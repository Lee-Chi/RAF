#include "Command.h"

namespace raf{ namespace kernel{
Command::Command(): status(WAIT), receiver(NULL)
{
}

Command::Command(Receiver* r): status(WAIT), receiver(r)
{
}

Command::~Command()
{
	if(receiver)
	{
		delete receiver;
		receiver = NULL;
	}
}

void Command::execute()
{
	receiver->execute()? setStatus(SUCCESS): setStatus(FAIL);
}

Status Command::getStatus() const
{
	return status;
}

void Command::setStatus(Status s)
{
	status = s;
}

}}