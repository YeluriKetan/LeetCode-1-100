#include "bits/stdc++.h"
using namespace std;

long long solve() {
    int n, s = 0; cin >> n;
    char ai;
    long long c = 0;
    unordered_map<int, int> offsetCount;
    offsetCount[0] = 1;
    while (n--) {
        cin >> ai;
        s += ai - '0' - 1;
        auto it = offsetCount.emplace(s, 0);
        c += it.first->second;
        it.first->second++;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}