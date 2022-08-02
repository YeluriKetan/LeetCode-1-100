#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, d12, d23, d31, a, b, c, maxLen, sideLen1, sideLen2, temp, connector, armLen, prev = 4;
    cin >> n >> d12 >> d23 >> d31;
    if (d12 >= d23 && d12 >= d31) {
        a = 1, b = 2, c = 3, maxLen = d12, sideLen1 = d31, sideLen2 = d23;
    } else if (d23 >= d12 && d23 >= d31) {
        a = 2, b = 3, c = 1, maxLen = d23, sideLen1 = d12, sideLen2 = d31;
    } else {
        a = 3, b = 1, c = 2, maxLen = d31, sideLen1 = d23, sideLen2 = d12;
    }
    temp = sideLen1 + sideLen2 - maxLen;
    if (temp < 0 || temp % 2) {
        cout << "NO\n";
        return;
    }
    armLen = temp / 2;
    if (maxLen + 1 + armLen > n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    connector = sideLen1 - armLen;
    vector<int> horizontal(maxLen + 1, 0), arm(n - maxLen - 1, 0);
    horizontal[0] = a, horizontal[maxLen] = b;
    if (armLen) {
        arm[armLen - 1] = c;
    } else {
        horizontal[sideLen1] = c;
    }
    for (int i = 0; i < maxLen + 1; ++i) {
        if (horizontal[i] == 0) {
            horizontal[i] = prev++;
        }
    }
    for (int i = 0; i < n - maxLen - 1; ++i) {
        if (arm[i] == 0) {
            arm[i] = prev++;
        }
    }
    for (int i = 1; i < maxLen + 1; ++i) {
        cout << horizontal[i - 1] << " " << horizontal[i] << "\n";
    }
    for (int i = 1; i < n - maxLen - 1; ++i) {
        cout << arm[i - 1] << " " << arm[i] << "\n";
    }
    if (n - maxLen - 1 > 0) {
        cout << horizontal[connector] << " " << arm[0] << "\n";
    }
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
