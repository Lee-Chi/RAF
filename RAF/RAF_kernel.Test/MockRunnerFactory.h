#include "RunnerFactory.h"
#include "MockRunner.h"

using namespace raf::kernel;

class MockRunnerFactory: public RunnerFactory
{
public:
	Runner* create() override
	{
		return new MockRunner();
	}
};