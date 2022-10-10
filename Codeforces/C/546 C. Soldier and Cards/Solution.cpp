#include "iostream"
#include "queue"
#include "unordered_set"
using namespace std;
typedef long long ll;
typedef queue<int> Q;

ll encode(Q &a, Q &b) {
    ll E = 0;
    for (int i = a.size(); i > 0; --i) {
        E <<= 4;
        E += a.front();
        a.push(a.front());
        a.pop();
    }
    E <<= 4;
    E += 0b1111;
    for (int i = b.size(); i > 0; --i) {
        E <<= 4;
        E += b.front();
        b.push(b.front());
        b.pop();
    }
    return E;
}

int main() {
    int N, ki, ci, p, q, T = 0; cin >> N;
    char W = '0';
    Q a, b;
    cin >> ki;
    while (ki--) {
        cin >> ci;
        a.push(ci);
        if (ci == N) W += 1;
    }
    cin >> ki;
    while (ki--) {
        cin >> ci;
        b.push(ci);
        if (ci == N) W += 2;
    }
    unordered_set<ll> S;
    ll e;
    while (!a.empty() && !b.empty()) {
        e = encode(a, b);
        if (S.find(e) == S.end()) {
            S.insert(e);
        } else {
            T = -1;
            break;
        }
        p = a.front(); a.pop();
        q = b.front(); b.pop();
        if (p > q) {
            a.push(q);
            a.push(p);
        } else {
            b.push(p);
            b.push(q);
        }
        T++;
    }
    cout << T << " " << (T > 0 ? W : ' ') << endl;
    return 0;
}
