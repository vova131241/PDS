#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab14/lab14.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab12test
{
	TEST_CLASS(Lab12test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 3;
			int** A = createMatrix(n);

			Assert::IsTrue(isIrreflexive(A, n));

			for (int i = 0; i < n; i++) delete[] A[i];
			delete[] A;
		}
	};
}
