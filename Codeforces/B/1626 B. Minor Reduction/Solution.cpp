#include <iostream>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int lastDouble = -1;
    for (int i = s.size() - 2; i > -1; --i) {
        if (s[i] + s[i + 1] - 96 > 9) {
            lastDouble = i;
            break;
        }
    }
    if (lastDouble != -1) {
        cout << s.substr(0, lastDouble);
        cout << (int) (s[lastDouble] + s[lastDouble + 1] - 96);
        cout << s.substr(lastDouble + 2, s.size() - lastDouble - 2);
    } else {
        cout << (int) (s[0] + s[1] - 96);
        cout << s.substr(2, s.size() - 2);
    }
    cout << "\n";
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
