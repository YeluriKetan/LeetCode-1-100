#include <iostream>

using namespace std;

long long solve() {
    long long a, s, ans = 0, power = 1;
    cin >> a >> s;
    int aUnit, sUnit;
    while (s > 0) {
        aUnit = a % 10;
        a /= 10;
        sUnit = s % 10;
        s /= 10;
        if (sUnit < aUnit) {
            sUnit += (s % 10) * 10;
            s /= 10;
        }
        if (sUnit < aUnit || sUnit > aUnit + 9) {
            return -1;
        } else {
            ans += (sUnit - aUnit) * power;
            power *= 10;
        }
    }
    return a > 0 ? -1 : ans;
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
