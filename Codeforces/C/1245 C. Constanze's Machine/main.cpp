#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    long long x = 1, y = 1, z = 1;
    char p = 'A';
    for (auto c: s) {
        if (c == 'm' || c == 'w') { z = 0; break; }
        if ((c == 'n' || c == 'u') && (p == c)) z += x;
        z %= 1000000007;
        p = c;
        x = y;
        y = z;
    }
    cout << z << endl;
    return 0;
}