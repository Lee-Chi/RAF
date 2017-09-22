#pragma once
#include "RunLogic.h"

using namespace raf::kernel;

class MockLogic: public Logic
{
public:
	MockLogic(){}
	virtual ~MockLogic(){}
	bool execute() override
	{
		return true;
	}
	string getDescription() override
	{
		return "MockLogic";
	}
};
