#include <iostream>
#include <vector>

using namespace std;

long long solve() {
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for (auto curr: s) {
        count[curr - 'a']++;
    }
    long long ans = 1;
    for (auto curr: count) {
        for (int i = 1; i <= curr; ++i) {
            ans *= i;
        }
    }
    return ans;
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
