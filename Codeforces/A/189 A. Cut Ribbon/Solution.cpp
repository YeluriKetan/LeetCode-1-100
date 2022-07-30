#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n, temp, maxCount = 0;
    vector<int> abc(3);
    cin >> n >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(), abc.end());
    for (int i = n / abc[0]; i >= 0; --i) {
        temp = n - (i * abc[0]);
        for (int j = temp / abc[1]; j >= 0; --j) {
            temp -= j * abc[1];
            if (temp % abc[2] == 0) {
                maxCount = max(maxCount, i + j + temp / abc[2]);
            }
            temp += j * abc[1];
        }
    }
    return maxCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
