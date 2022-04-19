#include <iostream>
#include <set>

using namespace std;

string solve(int n) {
    set<int> tracker;
    int curr;
    bool zero = false, one = false, cons = false;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        switch (curr) {
            case 0:
                zero = true;
                break;
            case 1:
                one = true;
                break;
            default:
                if (tracker.find(curr - 1) != tracker.end() || tracker.find(curr + 1) != tracker.end()) {
                    cons = true;
                } else {
                    tracker.insert(curr);
                }
                break;
        }
    }
    if (one) {
        if (zero || tracker.find(2) != tracker.end() || cons) {
            return "NO";
        } else {
            return "YES";
        }
    } else {
        return "YES";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
