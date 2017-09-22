#include "stdafx.h"
#include "CppUnitTest.h"

#include "CompositeRunner.h"
#include "MockRunner.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace raf::kernel;

namespace RAF_kernelTest
{
	TEST_CLASS(CompositeRunnerTest)
	{
	private:
		CompositeRunner* runners;

	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			runners = new CompositeRunner();
		}
		TEST_METHOD_CLEANUP(tearDown)
		{
			delete runners;
		}

		TEST_METHOD(CompositeRunner_isContain)
		{
			Assert::IsFalse(runners->isContain());

			runners->add(new MockRunner());
			Assert::IsTrue(runners->isContain());
		}

		TEST_METHOD(CompositeRunner_add)
		{
			Assert::AreEqual(0, runners->size());

			runners->add(new MockRunner());
			runners->add(new MockRunner(true, false, true));
			Assert::AreEqual(2, runners->size());
		}

		TEST_METHOD(CompositeRunner_run)
		{
			Assert::AreEqual(0, runners->size());

			runners->add(new MockRunner());
			Assert::IsTrue(runners->run());

			runners->add(new MockRunner(true, false, true));
			Assert::IsFalse(runners->run());
		}

		TEST_METHOD(CompositeRunner_run_killrunners)
		{
			Assert::AreEqual(0, runners->size());

			Runner* runner = new MockRunner(true, false, true);
			runners->add(runner);
			Assert::AreEqual(1, runners->size());

			runners->add(new MockRunner());
			Assert::IsFalse(runners->run());

			runner->kill();
			Assert::IsTrue(runners->run());
			Assert::AreEqual(1, runners->size());
		}
	};
}