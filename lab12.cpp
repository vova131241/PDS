#include <iostream>
#include <fstream>

const int INF = 1000000000;

// --- Ôóíêö³¿ ---
int** readGraph(const std::string& filename, int& n) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Cannot open file " << filename << "\n";
        return nullptr;
    }

    fin >> n;
    int** g = new int* [n];
    for (int i = 0; i < n; i++) {
        g[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fin >> g[i][j];
            if (g[i][j] == 0 && i != j)
                g[i][j] = INF;
        }
    }
    return g;
}

void dijkstra(int** g, int n, int start, int* dist, int* parent) {
    bool* used = new bool[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        used[i] = false;
    }
    dist[start] = 0;

    for (int iter = 0; iter < n; iter++) {
        int v = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;

        if (dist[v] == INF) break;
        used[v] = true;

        for (int u = 0; u < n; u++) {
            if (dist[v] + g[v][u] < dist[u]) {
                dist[u] = dist[v] + g[v][u];
                parent[u] = v;
            }
        }
    }
    delete[] used;
}

void printDistances(int* dist, int n) {
    for (int i = 0; i < n; i++) {
        if (dist[i] >= INF)
            std::cout << i + 1 << ": no path\n";
        else
            std::cout << i + 1 << ": " << dist[i] << "\n";
    }
}

void printPath(int* parent, int finish) {
    int path[1000];
    int len = 0;
    for (int v = finish; v != -1; v = parent[v])
        path[len++] = v;

    for (int i = len - 1; i >= 0; i--)
        std::cout << path[i] + 1 << " ";
    std::cout << "\n";
}

// --- main ---
int main() {
    int n;
    int** g = readGraph("lab12text.txt", n);
    if (!g) return 1;

    std::cout << "Enter start vertex (1.." << n << "): ";
    int start;
    std::cin >> start;
    start--;

    int* dist = new int[n];
    int* parent = new int[n];

    dijkstra(g, n, start, dist, parent);

    std::cout << "Choose mode:\n";
    std::cout << "(1) - distance between two vertices\n";
    std::cout << "(2) - distances from start to all\n";

    std::cout << std::endl;

    int mode;
    std::cin >> mode;

    if (mode == 2) {
        printDistances(dist, n);
    }
    else if (mode == 1) {
        std::cout << "Enter finish vertex: ";
        int finish;
        std::cin >> finish;
        finish--;

        if (dist[finish] >= INF)
            std::cout << "No path.\n";
        else {
            std::cout << "Shortest distance: " << dist[finish] << "\n";
            std::cout << "Path: ";
            printPath(parent, finish);
        }
    }

    for (int i = 0; i < n; i++) delete[] g[i];
    delete[] g;
    delete[] dist;
    delete[] parent;

    return 0;
}
