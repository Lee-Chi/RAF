#pragma once

#include "Runner.h"

namespace raf{ namespace kernel{

class RunnerFactory
{
public:
	RunnerFactory(){}
	virtual ~RunnerFactory(){}

	virtual Runner* create() = 0;
};


}}