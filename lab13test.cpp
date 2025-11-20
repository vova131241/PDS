#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab13/lab13.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab13test
{
	TEST_CLASS(lab13test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int n; 

            // Створимо тестовий файл графа
            std::ofstream fout("test_graph.txt");
            fout << "5 6\n";
            fout << "1 2\n1 4\n2 3\n3 5\n4 3\n4 5\n";
            fout.close();

            // Використовуємо readGraph()
            bool g = readGraph("test_graph.txt");
            if (!g) Assert::Fail(L"readGraph failed");
		}
	};
}
