#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9/lab_9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab9test
{
	TEST_CLASS(lab9test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int graph[MAX][MAX];
			int n;
			Assert::IsTrue(LoadGraph("C:\\Users\\Admin\\Desktop\\Дискретна\\Lab_9\\Lab_9\\lab9_text.txt", graph, n));
			Assert::AreEqual(4, n);
			Assert::AreEqual(1, graph[0][1]);
		}
	};
}
