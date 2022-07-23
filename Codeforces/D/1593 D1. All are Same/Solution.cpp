#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    if (vec[0] == vec[n - 1]) {
        return -1;
    }
    int ans = vec[1] - vec[0];
    for (int i = 2; i < n; ++i) {
        ans = gcd(vec[i] - vec[0], ans);
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
