#include <iostream>

using namespace std;

string solve(string s, char c) {
    for (int i = s.size() - 1; i > -1; i -= 2) {
        if (s[i] == c) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    string s;
    char c;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s >> c;
        cout << solve(s, c) << "\n";
    }
    return 0;
}
