#include "bits/stdc++.h"
using namespace std;

bool isPrime(int n) {
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= (int) sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve() {
    int n; cin >> n;
    if (n < 4 || n == 5) {
        return 1;
    } else if (n % 2) {
        return isPrime(n)
            ? 1
            : isPrime(n - 2)
                ? 2
                : 3;
    } else {
        return 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}