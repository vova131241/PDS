#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_2/lab5_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab52test
{
	TEST_CLASS(lab52test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int result = CalculateAnd(1, 0);
			int actual = 0;

			Assert::AreEqual(result, actual);
		}
	};
}
