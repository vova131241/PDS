#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_1/lab5_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab51test
{
	TEST_CLASS(lab51test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string D[12];
			Calculate(D);

			string result = "a11";
			string actual = D[3];

			Assert::AreEqual(result, actual);
		}
	};
}
