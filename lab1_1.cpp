#include <iostream>
using namespace std;

void Calculate(int p, int q);
bool Conjuncted(int p, int q);

int main() {
    bool p, q;
    cout << "Choose value for p (0 or 1): ";
    cin >> p;
    cout << "Choose value for q (0 or 1): ";
    cin >> q;

    Calculate(p, q);

    return 0;
}

void Calculate(int p, int q) {
    bool conjunction = Conjuncted(p, q);
    bool disjunction = p || q;
    bool xorValue = p ^ q;
    bool imp_pq = (!p) || q;
    bool imp_qp = (!q) || p;
    bool equivalence = ((!p) || q) && ((!q) || p);

    cout << "p = " << p << ", q = " << q << endl;
    cout << "conjunction (p AND q): " << conjunction << endl;
    cout << "disjunction (p OR q): " << disjunction << endl;
    cout << "xorValue (XOR): " << xorValue << endl;
    cout << "imp_pq p → q: " << imp_pq << endl;
    cout << "imp_qp q → p: " << imp_qp << endl;
    cout << "equivalence (p ↔ q): " << equivalence << endl;
}

bool Conjuncted(int p, int q) {
    return p && q;
}
