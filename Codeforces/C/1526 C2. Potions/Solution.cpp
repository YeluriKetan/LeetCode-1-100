#include "bits/stdc++.h"
using namespace std;

int solve() {
    long long n, ai, h = 0, count = 0; cin >> n;
    priority_queue<long long> pq;
    while (n--) {
        cin >> ai;
        if (ai >= 0) {
            h += ai;
            count++;
        } else {
            if (ai + h >= 0) {
                h += ai;
                count++;
                pq.push(-ai);
            } else if (!pq.empty() && pq.top() > -ai) {
                h += pq.top() + ai; pq.pop();
                pq.push(-ai);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}