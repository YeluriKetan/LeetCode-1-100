#include <iostream>
#include <vector>

using namespace std;

string solve() {
    string s;
    cin >> s;
    vector<bool> present(26, false);
    for (auto currChar: s) {
        present[currChar - 'a'] = true;
    }
    int count = 0;
    for (auto currBool: present) {
        if (currBool) {
            count++;
        }
    }
    return count % 2 ? "IGNORE HIM!" : "CHAT WITH HER!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
