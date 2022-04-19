#include <iostream>

using namespace std;

void solve(int n) {
    string s;
    cin >> s;
    int total = 0;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (i == n - 1) {
                left = 1;
            } else {
                total++;
                i++;
                left = n - i - 1;
            }
        } else {
            left = n - i;
            i++;
            while (i < n && s[i] == '(') {
                i++;
            }
            if (i < n) {
                total++;
                left = n - i - 1;
            }
        }
    }
    cout << total << " " << left << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        solve(n);
    }
    return 0;
}
