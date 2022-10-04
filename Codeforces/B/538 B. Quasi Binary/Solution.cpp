#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
typedef pair<int, int> ii;

bool cmp(ii &a, ii &b) {
    return a.first > b.first;
}

int main() {
    int N, p = 1, t; cin >> N;
    vector<ii> D;
    while (N > 0) {
        t = N % 10;
        if (t) D.emplace_back(t, p);
        p *= 10;
        N /= 10;
    }
    sort(D.begin(), D.end(), cmp);
    vector<int> ans(D[0].first, 0);
    for (auto &[C, P]: D) {
        for (int i = 0; i < C; ++i) ans[i] += P;
    }
    cout << D[0].first << "\n";
    for (auto &I: ans) cout << I << " ";
    cout << "\n";
    return 0;
}