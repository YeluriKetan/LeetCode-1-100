#include <iostream>
#include <cmath>

using namespace std;

long long solve() {
    string s, t;
    cin >> s >> t;
    for (auto currChar: t) {
        if (currChar == 'a') {
            return t.size() == 1 ? 1 : -1;
        }
    }
    return (long long) pow(2, s.size());
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
