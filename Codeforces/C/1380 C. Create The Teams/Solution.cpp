#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
typedef long long ll;

int solve() {
    ll n, x, prev, ans = 0; cin >> n >> x;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end());
    prev = n;
    for (ll i = n - 1; i > -1; --i) {
        if (vec[i] * (prev - i) >= x) {
            ans++;
            prev = i;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}