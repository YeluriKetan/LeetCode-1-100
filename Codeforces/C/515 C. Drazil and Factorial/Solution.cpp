#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s, ans;
    int count[10];
    memset(count, 0, sizeof count);
    cin >> n >> s;
    for (char curr: s) {
        switch (curr - '0') {
            case 0:
            case 1:
                break;
            case 2:
                count[2]++;
                break;
            case 3:
                count[3]++;
                break;
            case 4:
                count[3]++;
                count[2] += 2;
                break;
            case 5:
                count[5]++;
                break;
            case 6:
                count[5]++;
                count[3]++;
                break;
            case 7:
                count[7]++;
                break;
            case 8:
                count[7]++;
                count[2] += 3;
                break;
            case 9:
                count[7]++;
                count[3] += 2;
                count[2]++;
                break;
            default:
                break;
        }
    }
    for (int i = 9; i > 1; --i) {
        for (int j = 0; j < count[i]; ++j) {
            ans += to_string(i);
        }
    }
    cout << ans << "\n";
    return 0;
}
