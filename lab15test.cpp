#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab15/lab15.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab15test
{
	TEST_CLASS(lab15test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			n = 4;

			col[0] = 1; 
			col[1] = 3; 

			// Check if placing a queen at (2,0) is safe
			Assert::IsTrue(isSafe(2, 0));
		}
	};
}
