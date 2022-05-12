#include <iostream>
#include <vector>

using namespace std;

string solve() {
    string s;
    cin >> s;
    int pointer = 0, len = s.size();
    vector<bool> tracker(26, false);
    while (pointer < len) {
        if (tracker[s[pointer] - 'a']) {
            break;
        } else {
            tracker[s[pointer++] - 'a'] = true;
        }
    }
    int patternLen = pointer, repeatPointer = 0;
    while (pointer < len) {
        if (s[pointer] == s[repeatPointer]) {
            repeatPointer = (repeatPointer + 1) % patternLen;
            pointer++;
        } else {
            return "NO";
        }
    }
    return "YES";
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
