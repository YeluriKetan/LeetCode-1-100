#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> primeFactorization(int x) {
    unordered_map<int, int> factors;
    int limit = sqrt(x);
    for (int i = 2; i <= min(x, limit); i += i == 2 ? 1 : 2) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1) factors[x]++;
    return factors;
}

string solve() {
    int a, b, k; cin >> a >> b >> k;
    auto factorsA = primeFactorization(a);
    auto factorsB = primeFactorization(b);
    bool extraA = false, extraB = false;
    int numFactorsA = 0, numFactorsB = 0;
    for (auto &factor : factorsA) {
        numFactorsA += factor.second;
        auto it = factorsB.find(factor.first);
        if (it == factorsB.end() || it->second < factor.second) {
            extraA = true;
        }
    }
    for (auto &factor : factorsB) {
        numFactorsB += factor.second;
        auto it = factorsA.find(factor.first);
        if (it == factorsA.end() || it->second < factor.second) {
            extraB = true;
        }
    }
    int min = (extraA ^ extraB) ? 1 : 2, max = numFactorsA + numFactorsB;
    return (min <= k && k <= max) ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
