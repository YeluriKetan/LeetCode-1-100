#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    map<string, int> database;
    while (n-- > 0) {
        cin >> s;
        auto pointer = database.find(s);
        if (pointer == database.end()) {
            database[s] = 0;
            cout << "OK\n";
        } else {
            pointer->second++;
            cout << s << pointer->second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
