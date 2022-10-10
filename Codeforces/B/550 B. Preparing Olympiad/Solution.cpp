#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
typedef vector<int> VI;
typedef int I;

bool isValid(int B, VI &V, I L, I R, I X) {
    I C = 0, T = 0, i = 0, mi = 1e9, ma = 0;
    while (B) {
        if (B & 1) {
            mi = min(mi, V[i]);
            ma = max(ma, V[i]);
            T += V[i];
            C++;
        }
        B >>= 1;
        i++;
    }
    return C > 1 && L <= T && T <= R && ma - mi >= X;
}

int main() {
    I N, L, R, X, T = 0; cin >> N >> L >> R >> X;
    VI V(N);
    for (I i = 0; i < N; ++i) cin >> V[i];
    for (I i = (1 << N) - 1; i > 1; --i) {
        if (isValid(i, V, L, R, X)) T++;
    }
    cout << T << "\n";
    return 0;
}