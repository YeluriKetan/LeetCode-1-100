#include <iostream>

using namespace std;

int solve() {
    string s;
    cin >> s;
    int n = s.size();
    int firstZero = 0;
    while (firstZero < n && s[firstZero] != '0') {
        firstZero++;
    }
    int lastOne = n - 1;
    while (lastOne > -1 && s[lastOne] != '1') {
        lastOne--;
    }
    if (lastOne == -1 && firstZero == n) {
        return n;
    } else if (lastOne == -1) {
        return firstZero + 1;
    } else if (firstZero == n) {
        return n - lastOne;
    } else {
        return firstZero - lastOne + 1;
    }
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
