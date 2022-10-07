#include "iostream"
#include "vector"
#include "unordered_set"
#include "algorithm"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M, ki, aj, t, A = 0; cin >> N >> M;
    vector<int> S(M, -1);
    for (int i = 0; i < N; ++i) {
        cin >> ki;
        if (!ki) A++;
        while (ki--) {
            cin >> aj; aj--;
            t = S[aj];
            if (t != -1) {
                for (int k = 0; k < M; ++k) {
                    if (S[k] == t) {
                        S[k] = i;
                    }
                }
            }
            S[aj] = i;
        }
    }
    unordered_set<int> SS(S.begin(), S.end());
    SS.erase(-1);
    cout << (SS.size() > 0 ? SS.size() - 1 : 0) + A << "\n";
    return 0;
}