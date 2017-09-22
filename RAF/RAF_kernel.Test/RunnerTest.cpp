#include "stdafx.h"
#include "CppUnitTest.h"

#include "MockRunner.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RAF_kernelTest
{
	TEST_CLASS(RunnerTest)
	{
	public:
		TEST_METHOD(Runner_isDead)
		{
			Runner* runner = new MockRunner();
			Assert::IsFalse(runner->isDead());
			Assert::IsTrue(runner->initialize());
			Assert::IsTrue(runner->run());
			Assert::IsTrue(runner->finalize());
			Assert::AreEqual("MockRunner is alive.", runner->getDescription().c_str());

			runner->kill();
			Assert::IsTrue(runner->isDead());
			Assert::IsFalse(runner->initialize());
			Assert::IsFalse(runner->run());
			Assert::IsFalse(runner->finalize());
			Assert::AreEqual("MockRunner is dead.", runner->getDescription().c_str());

			delete runner;
		}
	};
}