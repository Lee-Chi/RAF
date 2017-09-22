#pragma once

#include "RunLogic.h"

namespace raf{ namespace kernel{

class Builder
{
public:
	Builder(){}
	virtual ~Builder(){}

	RunLogic* buildRunLogic()
	{
		RunLogic* runLogic = new RunLogic();
		runLogic->setLogic(buildLogic());
		return runLogic;
	}

protected:
	virtual Logic* buildLogic() = 0;
};

}}