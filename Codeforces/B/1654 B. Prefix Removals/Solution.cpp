#include <iostream>

using namespace std;

string solve(string s) {
    int finalApp[26];
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        finalApp[s[i] - 'a'] = i;
    }
    for (int i = 0; i < len; ++i) {
        if (finalApp[s[i] - 'a'] <= i) {
            return s.substr(i, len - i);
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}