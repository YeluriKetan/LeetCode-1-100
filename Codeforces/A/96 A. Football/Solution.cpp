#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    char prev = '0';
    int count = 0;
    for (char curr: s) {
        if (curr == prev) {
            count++;
        } else {
            prev = curr;
            count = 1;
        }
        if (count >= 7) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
