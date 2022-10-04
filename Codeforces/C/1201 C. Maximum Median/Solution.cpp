#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, K, c = 1, p; cin >> N >> K;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) cin >> V[i];
    sort(V.begin(), V.end());
    p = V[N / 2];
    for (int i = N / 2 + 1; i < N; ++i) {
        if (K / c + p >= V[i]) {
            K -= (V[i] - p) * c;
            c++;
            p = V[i];
        } else {
            break;
        }
    }
    cout << K / c + p << "\n";
    return 0;
}