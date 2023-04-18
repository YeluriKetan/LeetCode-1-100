#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, T, ai; cin >> N >> T;
    vector<bool> V(N + 1, false);
    V[1] = true;
    for (int i = 1; i < N; ++i) {
        cin >> ai;
        if (V[i] == 1) V[i + ai] = 1;
    }
    cout << (V[T] ? "YES" : "NO") << endl;
    return 0;
}