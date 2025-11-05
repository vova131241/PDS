#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10/lab10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab10test
{
	TEST_CLASS(lab10test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int graph[MAX][MAX];
			int n, m;

			Assert::IsTrue(LoadGraph("C:\\Users\\Admin\\Desktop\\Дискретна\\Lab_10\\Lab_10\\lab10_text.txt", graph, n, m));
			Assert::AreEqual(8, n);
			Assert::AreEqual(12, m);

			Assert::AreEqual(4, graph[0][1]);  // v1→v2
			Assert::AreEqual(6, graph[0][4]);  // v1→v5
			Assert::AreEqual(9999, graph[0][7]); // v1→v8 не існує
		}
	};
}
