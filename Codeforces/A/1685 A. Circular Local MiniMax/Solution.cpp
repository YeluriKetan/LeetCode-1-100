#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    if (n % 2) {
        cout << "NO\n";
        return;
    }
    sort(vec.begin(), vec.end());
    string ans;
    int prev = INT_MAX;
    for (int i = 0; i < n / 2; ++i) {
        if (prev > vec[i] && vec[i] < vec[i + n / 2]) {
            ans += to_string(vec[i]) + " " + to_string(vec[i + n / 2]) + " ";
            prev = vec[i + n / 2];
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << ans << "\n";
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
