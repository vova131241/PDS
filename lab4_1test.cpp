#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4_1/lab4_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab41test
{
	TEST_CLASS(lab41test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int perm[5];
			Init(perm, 5);

			int actual[5] = { 1, 2, 3, 4, 5 };

			Assert::AreEqual(perm[4], actual[4]);
		}
	};
}
