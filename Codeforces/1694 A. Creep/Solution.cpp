#include <iostream>

using namespace std;

string solve() {
    int a, b;
    cin >> a >> b;
    string ans;
    while (a && b) {
        ans += "01";
        a--;
        b--;
    }
    while (a) {
        ans += "0";
        a--;
    }
    while (b) {
        ans += "1";
        b--;
    }
    return ans;
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
