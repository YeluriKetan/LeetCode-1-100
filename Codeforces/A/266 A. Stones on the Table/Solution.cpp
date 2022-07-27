#include <iostream>

using namespace std;

int solve() {
    int n, count = 0;
    string s;
    char c = 0;
    cin >> n >> s;
    for (auto currChar: s) {
        if (currChar != c) {
            count++;
            c = currChar;
        }
    }
    return n - count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
