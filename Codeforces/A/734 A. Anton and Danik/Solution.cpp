#include "iostream"
#include "string"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, countA = 0;
    string s;
    cin >> n >> s;
    for (auto curr: s) {
        if (curr == 'A') {
            countA++;
        }
    }
    if (countA < n - countA) {
        cout << "Danik\n";
    } else if (countA == n - countA) {
        cout << "Friendship\n";
    } else {
        cout << "Anton\n";
    }
    return 0;
}