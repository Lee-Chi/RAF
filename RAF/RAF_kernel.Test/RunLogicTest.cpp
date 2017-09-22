#include "stdafx.h"
#include "CppUnitTest.h"

#include "MockRunLogic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace raf::kernel;

namespace RAF_kernelTest
{
	TEST_CLASS(RunLogicTest)
	{
private:
		RunLogic* runLogic;
	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			runLogic = new RunLogic();
		}

		TEST_METHOD_CLEANUP(tearDown)
		{
			delete runLogic;
		}

		TEST_METHOD(Robot_setState)
		{
			Assert::AreEqual("Logic = NullLogic Please check.", runLogic->getDescription().c_str());

			runLogic->setLogic(new MockLogic());
			Assert::AreEqual("Logic = MockLogic", runLogic->getDescription().c_str());
		}

		TEST_METHOD(Robot_doAction)
		{
			Assert::IsFalse(runLogic->doAction());

			runLogic->setLogic(new MockLogic());
			Assert::IsTrue(runLogic->doAction());
		}
	};
}