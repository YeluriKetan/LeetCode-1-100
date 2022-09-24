#include "bits/stdc++.h"
using namespace std;

bool isLucky(int i) {
    while (i > 0) {
        if (i % 10 == 4 || i % 10 == 7) {
            i /= 10;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n; cin >> n;
    for (int i = 4; i <= n;) {
        if (n % i == 0 && isLucky(i)) {
            cout << "YES\n";
            return 0;
        }
        if (i % 10 == 4) {
            i += 3;
        } else {
            i += 7;
        }
    }
    cout << "NO\n";
    return 0;
}