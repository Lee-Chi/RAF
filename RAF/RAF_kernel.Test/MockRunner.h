#pragma once

#include "Runner.h"

using namespace raf::kernel;

class MockRunner: public Runner
{
public:
	MockRunner(bool i=true, bool r=true, bool f=true): initResult(i), runResult(r), finalResult(f){}
	virtual ~MockRunner(){}
	bool _init() override
	{
		return initResult;
	}
	bool _run() override
	{
		return runResult;
	}
	bool _final() override
	{
		return finalResult;
	}

	string _getDescription() override
	{
		return "MockRunner";
	}

private:
	bool initResult;
	bool runResult;
	bool finalResult;
};