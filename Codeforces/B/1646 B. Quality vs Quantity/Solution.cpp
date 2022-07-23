#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    long long red = vec[n - 1], blue = vec[0] + vec[1];
    int left = 2, right = n - 2;
    while (left < right) {
        if (red > blue) {
            return "YES";
        }
        red += vec[right--];
        blue += vec[left++];
    }
    if (red > blue) {
        return "YES";
    }
    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
