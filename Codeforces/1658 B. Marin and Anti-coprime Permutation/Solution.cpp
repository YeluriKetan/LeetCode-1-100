#include <iostream>

using namespace std;

long long memo[1001];
int done;

long long factorial(int n) {
    for (int i = done + 1; i <= n; ++i) {
        memo[i] = (memo[i - 1] * i) % 998244353;
    }
    if (n > done) {
        done = n;
    }
    return memo[n];
}

long long solve(int n) {
    if (n % 2 == 1) {
        return 0;
    }
    long long ans = factorial(n / 2);
    return (ans * ans) % 998244353;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    memo[0] = 1;
    done = 0;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
