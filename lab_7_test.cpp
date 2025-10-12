#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7/lab_7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab7test
{
	TEST_CLASS(lab7test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[100] = "C:\\Users\\Admin\\Desktop\\Дискретна\\Lab_7\\lab_7_test\\x64\\Debug\\test.text";
			Graph graph = readGraphFromFile(filename);

			int expectedN = 6;
			int expectedM = 3;

			Assert::AreEqual(expectedN, graph.n);
			Assert::AreEqual(expectedM, graph.m);

			Assert::AreEqual(0, graph.edges[0].from);
			Assert::AreEqual(1, graph.edges[0].to);
			Assert::AreEqual(1, graph.edges[1].from);
			Assert::AreEqual(2, graph.edges[1].to);
			Assert::AreEqual(3, graph.edges[2].from);
			Assert::AreEqual(4, graph.edges[2].to);
		}
	};
}
