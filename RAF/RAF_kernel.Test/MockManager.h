#pragma once

#include "Manager.h"
	using raf::kernel::Manager;

class MockManager: public Manager
{
public:
	MockManager(bool ikg): isKeepGoing(ikg){}
	
	bool isKeepRun() override
	{
		return isKeepGoing;
	}
private:
	bool isKeepGoing;
};