#include <iostream>
#include <vector>

using namespace std;

string solve() {
    int n, ai;
    vector<int> count(10, 0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        count[ai % 10]++;
    }
    for (int a = 9; a > -1; --a) {
        if (count[a] == 0) {
            continue;
        }
        count[a]--;
        for (int b = a; b > -1; --b) {
            if (count[b] == 0) {
                continue;
            }
            count[b]--;
            if (a + b > 13) {
                if (count[23 - a - b] > 0) {
                    return "YES";
                }
            } else if (a + b > 3) {
                if (count[13 - a - b] > 0) {
                    return "YES";
                }
            } else {
                if (count[3 - a - b] > 0) {
                    return "YES";
                }
            }
            count[b]++;
        }
        count[a]++;
    }
    return "NO";
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
