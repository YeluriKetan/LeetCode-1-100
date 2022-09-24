#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int o, i, double1; cin >> o >> i;
    if ((i < o - 1) || (2 * o < i - 2)) {
        cout << "-1\n";
        return 0;
    }
    bool end0 = false;
    if (o > i) {
        end0 = true;
        o--;
    }
    double1 = max(i - o - 1, 0);
    if (i > o) {
        cout << "1";
        if (double1) {
            cout << "1";
            double1--;
        }
    }
    while (o--) {
        cout << "01";
        if (double1) {
            cout << "1";
            double1--;
        }
    }
    if (end0) {
        cout << "0";
    }
    return 0;
}