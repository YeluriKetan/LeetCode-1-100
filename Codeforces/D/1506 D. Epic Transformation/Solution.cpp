#include "bits/stdc++.h"
using namespace std;

int solve() {
    int N, p = 1e9 + 1, cC = 0, nC; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    for (int i = N - 1; i > -1; --i) {
        if (v[i] == p) {
            cC++;
        } else {
            pq.push(cC);
            cC = 1;
            p = v[i];
        }
    }
    pq.push(cC);
    while (!pq.empty()) {
        cC = pq.top(); pq.pop();
        while (cC > 0 && !pq.empty()) {
            nC = pq.top(); pq.pop();
            if (nC) {
                pq.push(nC - 1);
                cC--;
            }
        }
    }
    return cC;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}