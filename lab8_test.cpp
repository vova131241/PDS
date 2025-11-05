#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8/lab_8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab8test
{
	TEST_CLASS(lab8test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			top = -1; 
			Assert::AreEqual(true, isEmpty());

			push(1);
			Assert::AreEqual(false, isEmpty());

			int val = pop();
			Assert::AreEqual(1, val);

			Assert::AreEqual(true, isEmpty());
		}
	};
}
