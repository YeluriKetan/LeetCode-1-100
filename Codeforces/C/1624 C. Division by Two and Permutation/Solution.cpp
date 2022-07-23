#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve() {
    int n, curr;
    cin >> n;
    vector<int> vec(n);
    vector<bool> done(n + 1, false);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    bool hasValue;
    for (int i = n - 1; i > -1; --i) {
        curr = vec[i];
        while (curr > n) {
            curr /= 2;
        }
        hasValue = false;
        while (curr >= 1) {
            if (!done[curr]) {
                done[curr] = true;
                hasValue = true;
                break;
            } else {
                curr /= 2;
            }
        }
        if (!hasValue) {
            return "NO";
        }
    }
    return "YES";
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
