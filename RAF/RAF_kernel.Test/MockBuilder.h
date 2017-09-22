#pragma once

#include "Builder.h"
	using raf::kernel::Builder;
#include "RunLogic.h"
	using raf::kernel::RunLogic;
	using raf::kernel::Logic;
	using raf::kernel::NullLogic;

class MockBuilder: public Builder
{
public:
	MockBuilder(){}
	virtual ~MockBuilder(){}

	Logic* buildLogic() override
	{
		return new NullLogic();
	}
};
