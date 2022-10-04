#include "iostream"
#include "algorithm"
using namespace std;

void solve() {
    int n, ai, bi, t; cin >> n;
    while (n--) {
        cin >> ai;
        t = 2; bi = 1;
        while (t <= 1e9) {
            if (abs(t - ai) < abs(bi - ai)) bi = t;
            t <<= 1;
        }
        cout << bi << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}