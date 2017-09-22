#include "stdafx.h"
#include "CppUnitTest.h"

#include "MockRunnerFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace raf::kernel;

namespace RAF_kernelTest
{
	TEST_CLASS(RunnerFactoryTest)
	{
	public:
		
		TEST_METHOD(RunnerFactory_create)
		{
			Runner* runner = MockRunnerFactory().create();
			Assert::AreEqual("MockRunner is alive.", runner->getDescription().c_str());
		}

	};
}