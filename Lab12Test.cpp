#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12/lab12.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab12Test
{
	TEST_CLASS(Lab12Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int n = 4;
            int** g = new int* [n];
            for (int i = 0; i < n; i++) g[i] = new int[n];

            int w[4][4] = {
                {0, 1, 4, 0},
                {0, 0, 2, 6},
                {0, 0, 0, 3},
                {0, 0, 0, 0}
            };

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    g[i][j] = (w[i][j] == 0 && i != j) ? INF : w[i][j];

            int dist[4];
            int parent[4];
            dijkstra(g, n, 0, dist, parent);

            Assert::AreEqual(0, dist[0]);
            Assert::AreEqual(1, dist[1]);
            Assert::AreEqual(3, dist[2]);
            Assert::AreEqual(6, dist[3]);
		}
	};
}
