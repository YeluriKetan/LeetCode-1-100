#include <iostream>

using namespace std;

int aCounter[26];
int bCounter[26];

string solve(string a, string b) {
    for (int i = 0; i < 26; ++i) {
        aCounter[i] = bCounter[i] = 0;
    }
    int aPointer = a.size() - 1, bPointer = b.size() - 1;
    while (bPointer > -1) {
        while (aPointer >= bPointer && a[aPointer] != b[bPointer]) {
            aCounter[a[aPointer] - 'A']++;
            aPointer--;
        }
        if (aPointer < bPointer) {
            return "NO";
        } else {
            if (aCounter[a[aPointer] - 'A'] == bCounter[b[bPointer] - 'A']) {
                aCounter[a[aPointer] - 'A']++;
                bCounter[b[bPointer] - 'A']++;
                bPointer--;
                aPointer--;
            } else {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    string a, b;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
