#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n, temp;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    if (n % 2) {
        long long total = 0;
        for (int i = 1; i < n; i += 2) {
            temp = max(vec[i - 1], vec[i + 1]);
            if (vec[i] <= temp) {
                total += temp + 1 - vec[i];
            }
        }
        return total;
    } else {
        vector<long long> a;
        a.push_back(0);
        long long total = 0;
        for (int i = 1; i < n - 1; i += 2) {
            temp = max(vec[i - 1], vec[i + 1]);
            if (vec[i] <= temp) {
                total += temp + 1 - vec[i];
            }
            a.push_back(total);
        }
        long long minVal = total;
        total = 0;
        int currPointer = a.size() - 2;
        for (int i = n - 2; i > 0; i -= 2) {
            temp = max(vec[i - 1], vec[i + 1]);
            if (vec[i] <= temp) {
                total += temp + 1 - vec[i];
            }
            minVal = min(minVal, a[currPointer] + total);
            currPointer--;
        }
        return minVal;
    }
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
