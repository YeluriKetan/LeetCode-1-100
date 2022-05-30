#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<bool> digits(long long x) {
    vector<bool> digitPresence(10, false);
    int temp;
    while (x > 0) {
        temp = x % 10;
        x /= 10;
        digitPresence[temp] = true;
    }
    return digitPresence;
}

int minOper(int n, long long x, map<long long, int> &done) {
    if (done.count(x)) {
        return done[x];
    }
    int currCount = to_string(x).size();
    if (currCount >= n) {
        done[x] = 0;
        return 0;
    }
    vector<bool> digitPresence = digits(x);
    int minVal = INT_MAX, temp;
    for (int i = 9; i > 1; i--) {
        if (digitPresence[i]) {
            temp = minOper(n, x * i, done);
            if (temp != -1) {
                minVal = min(minVal, temp + 1);
            }
            if (minVal == n - currCount) {
                break;
            }
        }
    }
    if (minVal == INT_MAX) {
        minVal = -1;
    }
    done[x] = minVal;
    return minVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long x;
    cin >> n >> x;
    map<long long, int> done;
    cout << minOper(n, x, done) << "\n";
    return 0;
}
