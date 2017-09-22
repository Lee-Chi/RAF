#include "stdafx.h"
#include "CppUnitTest.h"

#include "MockManager.h"
#include "MockRunner.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace raf::kernel;

namespace RAF_kernelTest
{
	TEST_CLASS(ManagerTest)
	{
	private:
		Manager* manager;
	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			manager = new MockManager(false);
		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete manager;
		}
		TEST_METHOD(manager_initialize)
		{
			Assert::IsFalse(manager->initialize());

			manager->setRunner(new MockRunner());

			Assert::IsTrue(manager->initialize());
		}

		TEST_METHOD(manager_run)
		{
			Assert::IsFalse(manager->run());

			manager->setRunner(new MockRunner());
			Assert::IsTrue(manager->run());

			manager->setRunner(new MockRunner(true, false, true));
			Assert::IsFalse(manager->run());
		}

		TEST_METHOD(manager_finalize)
		{
			Assert::IsFalse(manager->finalize());

			manager->setRunner(new MockRunner());
			Assert::IsTrue(manager->finalize());
		}
	};
}