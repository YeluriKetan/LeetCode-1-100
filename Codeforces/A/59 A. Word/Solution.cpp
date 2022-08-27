#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int countLower = 0;
    string s, ans;
    cin >> s;
    for (char c: s) {
        if (islower(c)) {
            countLower++;
        }
    }
    if (countLower >= s.size() - countLower) {
        for (char c: s) {
            ans += tolower(c);
        }
    } else {
        for (char c: s) {
            ans += toupper(c);
        }
    }
    cout << ans << "\n";
    return 0;
}
