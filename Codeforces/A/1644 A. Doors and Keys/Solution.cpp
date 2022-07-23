#include <iostream>

using namespace std;

string solve(string s) {
    bool r = true, g = true, b = true;
    for (auto curr: s) {
        switch(curr) {
            case 'R':
                if (r) { return "NO"; }
                break;
            case 'G':
                if (g) { return "NO"; }
                break;
            case 'B':
                if (b) { return "NO"; }
                break;
            case 'r':
                r = false;
                break;
            case 'g':
                g = false;
                break;
            case 'b':
                b = false;
                break;
            default:
                break;
        }
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}
