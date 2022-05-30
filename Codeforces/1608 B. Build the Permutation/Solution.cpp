#include <iostream>

using namespace std;

string solve() {
    int n, a, b, curr;
    cin >> n >> a >> b;
    if (a < b - 1 || b < a - 1 || a + b > n - 2) {
        return "-1";
    }
    string ans;
    if (a > b && b > 0) {
        ans = "1 3 2 ";
        a--;
        curr = 4;
    } else if (a <= b && a > 0) {
        ans = "2 1 ";
        curr = 3;
    } else if (a > b) {
        ans = "1 ";
        a--;
        curr = 2;
    } else {
        curr = 1;
    }
    while (a > 1 && b > 1) {
        ans += to_string(curr + 1) + " " + to_string(curr) + " ";
        curr += 2;
        a--;
        b--;
    }
    if (a == b) {
        for (int i = n; i >= curr; --i) {
            ans += to_string(i) + " ";
        }
    } else {
        ans += to_string(curr + 1) + " " + to_string(curr) + " ";
        for (int i = curr + 2; i <= n; ++i) {
            ans += to_string(i) + " ";
        }
    }
    return ans;
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
