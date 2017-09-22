#include "stdafx.h"
#include "CppUnitTest.h"

#include "MockBuilder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RAF_kernelTest
{
	TEST_CLASS(BuildTest)
	{
	public:
		
		TEST_METHOD(Builder_buildRunner)
		{
			Builder* builder = new MockBuilder();
			RunLogic* runLogic = builder->buildRunLogic();
			Assert::AreEqual(typeid(*runLogic).name(), "class raf::kernel::RunLogic");
			delete builder;
		}

	};
}