#include <iostream>

using namespace std;

string solve(int n, int r, int b) {
    int repeating = r / (b + 1);
    int topUp = r % (b + 1);
    string ans;
    ans.reserve(n);
    for (int i = 0; i < repeating; ++i) {
        ans += "R";
    }
    if (topUp > 0) {
        ans += "R";
        topUp--;
    }
    for (int i = 0; i < b; ++i) {
        ans += "B";
        for (int j = 0; j < repeating; ++j) {
            ans += "R";
        }
        if (topUp > 0) {
            ans += "R";
            topUp--;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, r, b;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> r >> b;
        cout << solve(n, r, b) << "\n";
    }
    return 0;
}
