#include "iostream"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    string hello = "hello";
    int pointer = 0;
    for (auto currChar: s) {
        if (currChar == hello[pointer]) {
            pointer++;
        }
        if (pointer == 5) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}