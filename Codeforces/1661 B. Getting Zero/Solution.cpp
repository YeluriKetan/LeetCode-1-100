#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

vector<int> memo(32768, -1);

void shortest() {
    memo[0] = 0;
    memo[16384] = memo[32767] = 1;
    int curr, temp, height = 2;
    unordered_set<int> visited;
    queue<int> q;
    q.push(16384);
    q.push(32767);
    while (!q.empty()) {
        for (int i = q.size(); i > 0; --i) {
            curr = q.front();
            q.pop();
            if (curr % 2 == 0) {
                temp = curr / 2;
                if (memo[temp] == -1) {
                    q.push(temp);
                    memo[temp] = height;
                }
                temp = 16384 + curr / 2;
                if (memo[temp] == -1) {
                    q.push(temp);
                    memo[temp] = height;
                }
            }
            temp = curr - 1;
            if (memo[temp] == -1) {
                memo[temp] = height;
                q.push(temp);
            }
        }
        height++;
    }
}

int solve() {
    int n;
    cin >> n;
    return memo[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    shortest();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << " ";
    }
    cout << "\n";
    return 0;
}
