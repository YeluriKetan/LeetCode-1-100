#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solve() {
    int n, ai;
    cin >> n;
    vector<int> vec(n);
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = n - 1; i > -1; --i) {
        if (seen.find(vec[i]) == seen.end()) {
            seen.insert(vec[i]);
        } else {
            return i + 1;
        }
    }
    return 0;
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
