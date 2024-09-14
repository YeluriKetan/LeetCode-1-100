#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;
typedef long long ll;
#define MOD 100000000l

class Permutator {
    // prevSubDp[i] = number of ways to arrange i men in g - 1 groups
    // used to calculate number of ways to arrange i men in g groups
    VI prevSubDp; // init case: 1 way to 0...n men in 1 group
    VI dp; // dp[i] = number of ways to arrange men in i groups
    int n, k;

public:
    Permutator(int _n, int _k): n(_n), k(_k) {
        if (n > k) dp = {0, 0};
        else dp = {0, 1};
        prevSubDp = VI(n + 1, 0);
        fill_n(prevSubDp.begin() + 1, min(n, k), 1);
    }

    int get(int i) {
        if (dp.size() < i + 1) {
            for (int j = dp.size(); j <= i; j++) {
                if (j > n) {
                    dp.push_back(0);
                } else {
                    VI nextSubDp(n + 1);
                    nextSubDp[0] = prevSubDp[0];
                    ll temp;
                    for (int x = 1; x <= n; x++) {
                        temp = (ll) nextSubDp[x - 1] + (ll) prevSubDp[x - 1];
                        if (x >= k + 1) temp -= prevSubDp[x - k - 1];
                        nextSubDp[x] = (int) ((temp + MOD) % MOD);
                    }
                    dp.push_back((int) (nextSubDp[n] % MOD));
                    prevSubDp = nextSubDp;
                }
            }
        }
        return dp[i];
    }
};

int solve() {
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    Permutator p1(n1, k1), p2(n2, k2);
    int sum = 0;
    for (int i = 1; i <= n1; i++) { // iterate through number of footmen groups
        if ((n1 + i - 1) / i > k1) continue; // if any footmen group has more than k1 footmen, skip
        ll currSum = 0, curr = p1.get(i);
        currSum = (currSum + curr * (ll) p2.get(i + 1)) % MOD;
        currSum = (currSum + 2 * curr * ((ll) p2.get(i))) % MOD;
        currSum = (currSum + curr * (ll) p2.get(i - 1)) % MOD;

        sum = (sum + currSum) % MOD;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}