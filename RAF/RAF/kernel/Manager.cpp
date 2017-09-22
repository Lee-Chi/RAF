#include <Windows.h>
#include "Manager.h"

namespace raf{ namespace kernel{

Manager::Manager(): runner(NULL)
{
}

Manager::~Manager()
{
	if(runner)
	{
		runner->finalize();
		delete runner;
		runner = NULL;
	}
}

void Manager::setRunner(Runner* r)
{
	runner = r;
}

bool Manager::initialize()
{
	return (runner)? runner->initialize(): false;
}

bool Manager::run()
{
	return (runner)? runner->run(): false;
}

bool Manager::finalize()
{
	return (runner)? runner->finalize(): false;
}

State Manager::runMain()
{
	if(!initialize()) return INITIALIZE_FAIL;

	while(isKeepRun())
	{
		run();
		Sleep(30);
	}

	if(!finalize()) return FINALIZE_FAIL;

	return SUCCESS;
}

}}