#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, temp, count = 0, currMin = 1000000000;
    cin >> n >> m;
    if (n >= m) {
        cout << n - m << "\n";
        return 0;
    }
    queue<int> q;
    vector<bool> visited(m + 1, false);
    visited[0] = true;
    q.push(n);
    while (!q.empty()) {
        for (int i = q.size(); i > 0; --i) {
            temp = q.front();
            q.pop();
            if (temp == m) {
                cout << min(count, currMin) << "\n";
                return 0;
            } else if (temp < m) {
                if (!visited[temp]) {
                    visited[temp] = true;
                    if ((temp * 2) > m || !visited[temp * 2]) {
                        q.push(temp * 2);
                    }
                    if (!visited[temp - 1]) {
                        q.push(temp - 1);
                    }
                }
            } else {
                currMin = min(currMin, count + temp - m);
            }
        }
        count++;
    }
    cout << currMin << "\n";
    return 0;
}
