#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    long long h, n, p, curr = 1, total = 0;
    cin >> h >> p;
    n = (long long) pow(2, h) - 1;
    while (n > 0) {
        curr = min(curr, p);
        if (curr == p) {
            total += (n - 1) / p + 1;
            break;
        }
        n -= curr;
        curr *= 2;
        total++;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}