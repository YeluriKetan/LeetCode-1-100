#include <iostream>
using namespace std;

string solve() {
    int n, pointer = 1;
    string s;
    cin >> n >> s;
    if (pointer < n && s[pointer] < s[pointer - 1]) {
        while (pointer < n && s[pointer] <= s[pointer - 1]) {
            pointer++;
        }
    }
    s = s.substr(0, pointer);
    return s + string(s.rbegin(), s.rend());
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
// cbba