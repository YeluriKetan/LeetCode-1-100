#include <iostream>

using namespace std;

string solve() {
    int n;
    long long prev = 0, ai;
    cin >> n;
    bool end = false;
    bool onlyZeroes = false;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (onlyZeroes) {
            if (ai != 0) {
                end = true;
            }
            continue;
        }
        if (end) {
            continue;
        }
        prev = ai + prev;
        if (prev < 0) {
            end = true;
        } else if (prev == 0) {
            onlyZeroes = true;
        }
    }
    if (prev != 0) {
        end = true;
    }
    return end ? "NO" : "YES";
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
