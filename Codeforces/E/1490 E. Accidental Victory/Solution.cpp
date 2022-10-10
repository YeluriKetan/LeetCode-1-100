#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
typedef pair<int, int> ii;

bool cmp(ii &a, ii &b) {
    return a.first > b.first;
}

void solve() {
    int N, ai; cin >> N;
    int C = N;
    long long S = 0;
    vector<ii> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> ai;
        V[i] = {ai, i + 1};
        S += ai;
    }
    sort(V.begin(), V.end(), cmp);
    S -= V[0].first;
    for (int i = 1; i < N; ++i) {
        if (S < V[i - 1].first) {
            C = i;
            break;
        } else {
            S -= V[i].first;
        }
    }
    vector<int> A;
    while (C) A.push_back(V[--C].second);
    sort(A.begin(), A.end());
    cout << A.size() << "\n";
    for (auto &a: A) cout << a << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}