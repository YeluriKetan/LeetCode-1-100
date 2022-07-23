#include <iostream>

using namespace std;

bool checkABC(string &s, int n, int begin) {
    return -1 < begin && begin < n - 2 && s[begin] == 'a' && s[begin + 1] == 'b' && s[begin + 2] == 'c';
}

void solve() {
    int n, q, i;
    string s;
    char c;
    cin >> n >> q >> s;
    int total = 0;
    for (int j = 0; j < n - 2; ++j) {
        if (checkABC(s, n, j)) {
            total++;
            j += 2;
        }
    }
    while (q-- > 0) {
        cin >> i >> c;
        i--;
        if (checkABC(s, n, i - 2) || checkABC(s, n, i - 1) || checkABC(s, n, i)) {
            total--;
        }
        s[i] = c;
        if (checkABC(s, n, i - 2) || checkABC(s, n, i - 1) || checkABC(s, n, i)) {
            total++;
        }
        cout << total << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
