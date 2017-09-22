#include "stdafx.h"
#include "CppUnitTest.h"

#include "MockCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace RAF_kernelTest
{
	TEST_CLASS(CommandTest)
	{
	public:
		TEST_METHOD(Command_execute_true)
		{
			Receiver* receiver = new MockReceiverTrue();
			Command command(receiver);

			command.execute();

			Assert::AreEqual((int)SUCCESS, (int)(command.getStatus()));
		}

		TEST_METHOD(Command_execute_false)
		{
			Receiver* receiver = new MockReceiverFalse();
			Command command(receiver);

			command.execute();

			Assert::AreEqual((int)FAIL, (int)(command.getStatus()));
		}
	};
}