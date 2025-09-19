#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3_2/lab3_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab32test
{
	TEST_CLASS(lab32test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int expectation = CalculateNByValue(15);
			int actual = 20;

			Assert::AreEqual(expectation, actual);
		}
	};
}
