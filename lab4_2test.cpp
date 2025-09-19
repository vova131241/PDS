#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4_2/lab4_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab42test
{
	TEST_CLASS(lab42test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int comb[5];
			Init(comb, 5);

			int actual[5] = { 1, 2, 3, 4, 5 };

			Assert::AreEqual(comb[4], actual[4]);
		}
	};
}
