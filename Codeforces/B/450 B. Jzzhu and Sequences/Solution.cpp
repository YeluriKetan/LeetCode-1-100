#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int x, y, n, mod = 1000000007, ans = 0;
    cin >> x >> y >> n;
    n %= 6;
    switch (n) {
        case 0:
            ans = x - y;
            break;
        case 1:
            ans = x;
            break;
        case 2:
            ans = y;
            break;
        case 3:
            ans = y - x;
            break;
        case 4:
            ans = -x;
            break;
        case 5:
            ans = -y;
            break;
        default:
            break;
    }
    while (ans < 0) {
        ans += mod;
    }
    cout << ans % mod << "\n";
    return 0;
}
