#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int m, s, temp, lastNonZero = 0;
    cin >> m >> s;
    if ((m > 1 && s == 0) || s > (m * 9)) {
        cout << "-1 -1\n";
        return 0;
    }
    string maxAns;
    for (int i = 0; i < m; ++i) {
        temp = min(9, s);
        maxAns += to_string(temp);
        s -= temp;
        if (temp) {
            lastNonZero = i;
        }
    }
    string minAns = maxAns;
    if (lastNonZero < m - 1) {
        minAns[lastNonZero]--;
        minAns[m - 1]++;
    }
    reverse(minAns.begin(), minAns.end());
    cout << minAns << " " << maxAns << "\n";
    return 0;
}