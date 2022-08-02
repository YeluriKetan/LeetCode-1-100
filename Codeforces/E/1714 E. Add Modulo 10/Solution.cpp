#include <iostream>
#include <vector>

using namespace std;

string solve() {
    int n, ai;
    bool zeroFound = false, oddTwo = false, evenTwo = false;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        while (ai % 10 != 0 && ai % 10 != 2) {
            ai += ai % 10;
        }
        if (ai % 10 == 0) {
            zeroFound = true;
        } else {
            if ((ai / 10) % 2) {
                oddTwo = true;
            } else {
                evenTwo = true;
            }
        }
        vec[i] = ai;
    }
    if (zeroFound) {
        for (int i = 1; i < n; ++i) {
            if (vec[i] != vec[i - 1]) {
                return "No";
            }
        }
        return "Yes";
    } else {
        if (oddTwo && evenTwo) {
            return "No";
        } else {
            return "Yes";
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
