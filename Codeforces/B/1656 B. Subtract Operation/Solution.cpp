#include <iostream>
#include <set>

using namespace std;

string solve(int n, int k) {
    set<int> tracker;
    int curr;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (ans) {
            continue;
        }
        if (tracker.find(curr - k) != tracker.end() || tracker.find(curr + k) != tracker.end()) {
            ans = true;
        } else {
            tracker.insert(curr);
        }
    }
    return ans ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
