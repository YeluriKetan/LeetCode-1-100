#include <iostream>

using namespace std;

string solve() {
    int n, ai;
    cin >> n;
    long long sum = 0;
    bool onePresent = false;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (ai == 1) {
            onePresent = true;
        }
        sum += ai - 2;
    }
    if (onePresent) {
        return "CHEF";
    }
    return (sum % 2) ? "CHEF" : "CHEFINA";
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
