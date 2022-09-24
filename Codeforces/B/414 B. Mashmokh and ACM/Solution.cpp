#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    long long temp;
    for (int i = n; i > 0; --i) {
        dp[i][0] = dp[i][1] = 1;
        for (int l = 2; l <= k; ++l) {
            temp = 0;
            for (int j = i; j <= n; j += i) {
                temp += dp[j][l - 1];
            }
            dp[i][l] = temp % 1000000007;
        }
    }
    temp = 0;
    for (int i = 1; i <= n; ++i) {
        temp += dp[i][k];
    }
    cout << temp % 1000000007 << "\n";
    return 0;
}