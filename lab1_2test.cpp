#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1_2/lab1_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab12test
{
	TEST_CLASS(lab12test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char result = CalculateOR('1', '0');
			char actual = '1';
			Assert::AreEqual(result, actual);
		}
	};
}
