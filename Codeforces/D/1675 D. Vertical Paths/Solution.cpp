#include <iostream>
#include <vector>

using namespace std;

string s;
int count;
int pairCount;
string ans;

void recurse(vector<vector<int>> &adjList, int node) {
    s += to_string(node) + " ";
    count++;
    if (adjList[node].empty()) {
        ans += to_string(count) + "\n" + s + "\n";
        s = "", count = 0;
        pairCount++;
        return;
    }
    for (auto curr: adjList[node]) {
        recurse(adjList, curr);
    }
}

string solve() {
    int n, pi, root;
    cin >> n;
    vector<vector<int>> adjList(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        cin >> pi;
        if (pi == i) {
            root = i;
            continue;
        }
        adjList[pi].push_back(i);
    }
    pairCount = 0, ans = "", s = "", count = 0;
    recurse(adjList, root);
    return to_string(pairCount) + "\n" + ans;
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
