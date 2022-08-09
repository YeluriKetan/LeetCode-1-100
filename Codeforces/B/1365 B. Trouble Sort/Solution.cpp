#include <iostream>

using namespace std;

string solve() {
    int n, prev = 0, ai, countType1 = 0;
    bool sorted = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (ai < prev) {
            sorted = false;
        }
        prev = ai;
    }
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (ai) {
            countType1++;
        }
    }
    if (sorted) {
        return "Yes";
    } else {
        if (countType1 && countType1 != n) {
            return "Yes";
        } else {
            return "No";
        }
    }
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
