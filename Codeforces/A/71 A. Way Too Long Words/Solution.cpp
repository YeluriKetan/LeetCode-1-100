#include <iostream>

using namespace std;

string solve() {
    string s;
    cin >> s;
    if (s.length() < 11) {
        return s;
    }
    return s[0] + to_string(s.length() - 2) + s[s.length() - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}
