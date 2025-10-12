#include <iostream>
#include <fstream>
#include <windows.h>

const int MAX_N = 100;
const int MAX_M = 1000;

struct Edge {
    int from;
    int to;
};

struct Graph {
    int n;
    int m;
    bool directed;
    Edge edges[MAX_M];
};

void calculateDegrees(const Graph& g) {
    int inDegree[MAX_N] = { 0 };
    int outDegree[MAX_N] = { 0 };

    for (int i = 0; i < g.m; i++) {
        int u = g.edges[i].from;
        int v = g.edges[i].to;

        outDegree[u]++;
        inDegree[v]++;
        if (!g.directed && u != v) {
            outDegree[v]++;
            inDegree[u]++;
        }
    }

    std::cout << "�������: �������� / ������� ������\n";
    for (int i = 0; i < g.n; i++) {
        std::cout << i << ": " << outDegree[i] << " / " << inDegree[i] << "\n";
    }

    // �������� ����������
    bool homogeneous = true;
    int degree = outDegree[0];
    for (int i = 1; i < g.n; i++) {
        if (outDegree[i] != degree) {
            homogeneous = false;
            break;
        }
    }
    if (homogeneous)
        std::cout << "���� ���������. ������ ����������: " << degree << "\n";
    else
        std::cout << "���� �� ���������.\n";
}


void findPendantAndIsolated(const Graph& g) {
    int inDegree[MAX_N] = { 0 };
    int outDegree[MAX_N] = { 0 };

    for (int i = 0; i < g.m; i++) {
        int u = g.edges[i].from;
        int v = g.edges[i].to;

        outDegree[u]++;
        inDegree[v]++;
        if (!g.directed && u != v) {
            outDegree[v]++;
            inDegree[u]++;
        }
    }

    std::cout << "������ �������: ";
    for (int i = 0; i < g.n; i++) {
        int degree = g.directed ? (inDegree[i] + outDegree[i]) : outDegree[i];
        if (degree == 1)
            std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "��������� �������: ";
    for (int i = 0; i < g.n; i++) {
        int degree = g.directed ? (inDegree[i] + outDegree[i]) : outDegree[i];
        if (degree == 0)
            std::cout << i << " ";
    }
    std::cout << "\n";
}

Graph readGraphFromFile(const char* filename) {
    Graph g;
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "�������: ���� �� ��������: " << filename << "\n";
        g.n = g.m = 0;
        g.directed = false;
        return g;
    }
    fin >> g.n >> g.m >> g.directed;
    for (int i = 0; i < g.m; i++) {
        fin >> g.edges[i].from >> g.edges[i].to;
    }
    return g;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char filename[100];
    std::cout << "������ ��'� ����� � ������: ";
    std::cin >> filename;

    Graph g = readGraphFromFile(filename);

    calculateDegrees(g);
    findPendantAndIsolated(g);

    return 0;
}