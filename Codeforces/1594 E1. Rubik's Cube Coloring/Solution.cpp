#include <iostream>

using namespace std;

long long solve() {
    int k;
    cin >> k;
    long long ans = 6, curr = 4;
    for (int i = 2; i <= k; ++i) {
        curr = (curr * curr) % 1000000007;
        ans = (ans * curr) % 1000000007;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
