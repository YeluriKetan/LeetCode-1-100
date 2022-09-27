#include "bits/stdc++.h"
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (!isupper(s[i])) {
            cout << s << "\n";
            return 0;
        }
    }
    s[0] = islower(s[0]) ? toupper(s[0]) : tolower(s[0]);
    for (int i = 1; i < s.size(); ++i) s[i] = tolower(s[i]);
    cout << s << "\n";
    return 0;
}