#include <iostream>

using namespace std;

int solve() {
    int n, x = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] == '+' || s[1] == '+') {
            x++;
        } else {
            x--;
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
