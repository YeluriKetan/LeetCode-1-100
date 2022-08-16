#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

void solve() {
    int n, y;
    long long x, ai, temp;
    cin >> n >> x >> y;
    priority_queue<long long, vector<long long>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        pq.push(ai);
    }
    while (y > 0) {
        ai = pq.top();
        pq.pop();
        temp = ai ^ x;
        if (temp <= ai) {
            if (y % 2) {
                pq.push(temp);
            } else {
                pq.push(ai);
            }
            y = 0;
        } else {
            pq.push(temp);
            y--;
        }
    }
    for (int i = 0; i < n; ++i) {
        ai = pq.top();
        pq.pop();
        cout << ai << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
