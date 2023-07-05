#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll solve() {
    ll n, currDiv = 1, currMul = 1; cin >> n;
    ll ans = n;
    while (currDiv <= 40) {
        currMul *= currDiv / gcd(currMul, currDiv);
        ans = (ans + (n / currMul)) % 1000000007;
        currDiv++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}