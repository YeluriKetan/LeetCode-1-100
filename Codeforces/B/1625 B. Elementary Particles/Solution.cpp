#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solve() {
    int n, ai;
    cin >> n;
    map<int, int> tracker;
    int maxLen = -1;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (tracker.find(ai) != tracker.end()) {
            maxLen = max(maxLen, tracker[ai] + n - i);
        }
        tracker[ai] = i;
    }
    return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}
