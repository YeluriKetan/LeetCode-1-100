#include "iostream"
#include "vector"
#include "map"
using namespace std;

int P[] = {4, 2, 2};

int main() {
    ios::sync_with_stdio(false);
    vector<int> V(100001, 0);
    int N, ai, Q, idx, t; cin >> N;
    char o;
    map<int, int, greater<>> M;
    auto r = M.emplace(0, 0).first;
    while (N--) {
        cin >> ai;
        V[ai]++;
    }
    for (auto &aiC: V) {
        if (aiC) {
            r = M.emplace(aiC, 0).first;
            r->second++;
        }
    }
    cin >> Q;
    while (Q--) {
        cin >> o >> ai;
        r = M.find(V[ai]);
        r->second--;
        if (!r->second) M.erase(r);
        V[ai] += (o == '+') ? 1 : -1;
        r = M.emplace(V[ai], 0).first;
        r->second++;
        idx = 0;
        for (auto &[k, v]: M) {
            if (idx == 3 || k < P[idx]) {
                break;
            }
            for (int i = 0; i < v; ++i) {
                t = k;
                while (idx < 3 && t >= P[idx]) {
                    t -= P[idx++];
                }
            }
        }
        cout << ((idx == 3) ? "YES\n" : "NO\n");
    }
    return 0;
}