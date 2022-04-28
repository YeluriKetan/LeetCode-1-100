#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int n, long long x) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int pointer = 0;
    long long currTotal = 0;
    while (true) {
        if (pointer < n && currTotal + vec[pointer] <= x) {
            currTotal += vec[pointer++];
        } else {
            pointer--;
            break;
        }
    }
    long long total = 0;
    long long temp;
    long long totalDays = 0;
    while (pointer > -1) {
        temp = (x - currTotal) / (pointer + 1L);
        total += (temp + 1L) * (pointer + 1L);
        currTotal += (temp + 1L) * (pointer + 1L);
        totalDays += temp + 1L;
        while (pointer > -1 && currTotal > x) {
            currTotal -= totalDays + vec[pointer--];
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    long long x;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> x;
        cout << solve(n, x) << "\n";
    }
    return 0;
}
