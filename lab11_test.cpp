#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11/lab_11.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab11test
{
	TEST_CLASS(lab11test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 3;
			int graph[MAX][MAX];
			int next[MAX][MAX];

			InitializeGraph(graph, next, n);
			graph[0][1] = 4; // 1 → 2

			FloydWarshall(graph, next, n);

			Assert::AreEqual(4, graph[0][1]);
			Assert::AreEqual(INF, graph[0][2]); // шлях відсутній
			Assert::AreEqual(0, graph[2][2]);   // до себе 0
		}
	};
}
