#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, temp;
    cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; ++i) {
        cin >> temp >> vec[i] >> temp;
    }
    sort(vec.begin(), vec.end());
    int checkNext = 1;
    for (auto curr: vec) {
        if (checkNext == curr) {
            checkNext++;
        } else if (checkNext < curr) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != checkNext) {
            cout << checkNext << " " << i << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
