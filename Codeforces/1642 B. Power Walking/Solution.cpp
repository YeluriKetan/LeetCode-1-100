#include <iostream>
#include <set>

using namespace std;

void solve(int n) {
    set<int> types;
    int curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        types.insert(curr);
    }
    curr = types.size();
    for (int i = 1; i <= n; ++i) {
        if (i <= curr) {
            cout << curr << " ";
        } else {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        solve(n);
    }
    return 0;
}
