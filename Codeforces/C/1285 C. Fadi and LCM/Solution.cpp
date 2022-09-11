#include "bits/stdc++.h"
using namespace std;

long long gcd(long long a, long long b) {
    if (b > a) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    long long X, minMax = LONG_LONG_MAX, temp, a, b; cin >> X;
    for (long long end = sqrt(X), i = 1; i <= end; i++) {
        if (X % i == 0 && gcd(i, X / i) == 1) {
            temp = max(i, X / i);
            if (temp < minMax) {
                minMax = temp;
                a = i, b = X / i;
            }
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}