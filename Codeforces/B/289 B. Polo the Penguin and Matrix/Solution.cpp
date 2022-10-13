#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int N, M, D, T, mid, ans = 0; cin >> N >> M >> D;
    T = N * M;
    vector<int> V(T);
    for (int i = 0; i < T; ++i) cin >> V[i];
    sort(V.begin(), V.end());
    mid = V[T / 2];
    for (auto &c: V) {
        if (abs(mid - c) % D == 0) {
            ans += abs(mid - c) / D;
        } else {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}