#include <iostream>

using namespace std;

string solve() {
    string s;
    cin >> s;
    s[0] = toupper(s[0]);
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
