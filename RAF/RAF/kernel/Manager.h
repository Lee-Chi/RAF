#pragma once

#include "Runner.h"

namespace raf{ namespace kernel{

enum State
{
	SUCCESS = 0,
	INITIALIZE_FAIL,
	RUN_FAIL,
	FINALIZE_FAIL
};

class Manager
{
public:
	Manager();
	virtual ~Manager();

	virtual bool isKeepRun() = 0;

	virtual void setRunner(Runner* r);
	virtual bool initialize();
	virtual bool run();
	virtual bool finalize();

	State runMain();
private:
	Runner* runner;
};

}}