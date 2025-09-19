#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3_1/lab3_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab31test
{
	TEST_CLASS(lab31test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			long expectation = Calculate(9, 4);
			long actual = 3024;

			Assert::AreEqual(expectation, actual);
		}
	};
}
