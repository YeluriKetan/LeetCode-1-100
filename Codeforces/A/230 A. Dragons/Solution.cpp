#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

bool cmp(ii &a, ii &b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    int S, N, xi, yi; cin >> S >> N;
    vector<ii> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> xi >> yi;
        D[i] = {xi, yi};
    }
    sort(D.begin(), D.end(), cmp);
    for (auto &[Xi, Yi]: D) {
        if (S > Xi) {
            S += Yi;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}