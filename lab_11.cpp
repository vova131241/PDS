#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MAX = 100;
const int INF = 1000000;

// --- 1. Функція ініціалізації графа ---
void InitializeGraph(int graph[MAX][MAX], int next[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
            next[i][j] = -1;
        }
    }
}

// --- 2. Функція зчитування графа з файлу ---
bool LoadGraphFromFile(const char* filename, int graph[MAX][MAX], int next[MAX][MAX], int& n, int& m)
{
    ifstream fin(filename);
    if (!fin.is_open())
        return false;

    fin >> n >> m;
    InitializeGraph(graph, next, n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
        next[u - 1][v - 1] = v - 1;
    }

    fin.close();
    return true;
}

// --- 3. Функція алгоритму Флойда-Уоршелла ---
void FloydWarshall(int graph[MAX][MAX], int next[MAX][MAX], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

// --- 4. Функція виводу матриці ---
void PrintMatrix(int graph[MAX][MAX], int n)
{
    cout << "\nМатриця найкоротших відстаней:\n";
    cout << setw(6) << " ";
    for (int i = 0; i < n; i++)
        cout << setw(6) << "v" << i + 1;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << "v" << i + 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                cout << setw(7) << "-";
            else
                cout << setw(7) << graph[i][j];
        }
        cout << endl;
    }
}

// --- 5. Функція виводу маршруту ---
void PrintPath(int next[MAX][MAX], int start, int end)
{
    cout << "Маршрут: v" << start + 1 << " ";
    int u = start;
    while (u != end)
    {
        u = next[u][end];
        if (u == -1) break;
        cout << "→ v" << u + 1 << " ";
    }
    cout << endl;
}

// --- 6. Основна програма ---
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m;
    int graph[MAX][MAX];
    int next[MAX][MAX];

    if (!LoadGraphFromFile("lab_11text.txt", graph, next, n, m))
    {
        cout << "Помилка відкриття файлу lab11_text.txt\n";
        return 1;
    }

    FloydWarshall(graph, next, n);
    PrintMatrix(graph, n);

    int start, end;
    cout << "\nВведіть початкову вершину: ";
    cin >> start;
    cout << "Введіть кінцеву вершину: ";
    cin >> end;
    start--; end--;

    if (graph[start][end] == INF)
        cout << "Немає шляху між цими вершинами.\n";
    else
    {
        cout << "Найкоротша відстань: " << graph[start][end] << endl;
        PrintPath(next, start, end);
    }

    return 0;
}