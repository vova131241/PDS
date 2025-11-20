#include <iostream>
#include <fstream>
using namespace std;

int** createMatrix(int n) {
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
    }
    return A;
}

bool isIrreflexive(int** A, int n) {
    for (int i = 0; i < n; i++)
        if (A[i][i] == 1)
            return false;
    return true;
}

bool isSymmetric(int** A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != A[j][i])
                return false;
    return true;
}

// ׳טעא÷ דנאפ ח פאיכף
void readGraph(const char* filename, int& n, int& m, int**& A) {
    ifstream fin(filename);
    fin >> n >> m;

    A = createMatrix(n);

    for (int i = 0; i < m; i++) {
        int v, u;
        fin >> v >> u;
        A[v - 1][u - 1] = 1;
    }

    fin.close();
}

int main() {
    int n, m;
    int** A;

    readGraph("lab14text.txt", n, m, A);

    cout << "Irreflexive: "
        << (isIrreflexive(A, n) ? "yes" : "no") << "\n";

    cout << "Symmetric: "
        << (isSymmetric(A, n) ? "yes" : "no") << "\n";

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
