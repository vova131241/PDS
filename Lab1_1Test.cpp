#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1_1/lab1_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab11Test
{
	TEST_CLASS(Lab11Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int q = 1;
			int p = 0;
			bool result = Conjuncted(q, p);
			bool expectation = false;
			Assert::AreEqual(result, expectation);
		}
	};
}
