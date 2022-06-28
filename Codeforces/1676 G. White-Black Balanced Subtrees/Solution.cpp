#include <iostream>
#include <vector>

using namespace std;

pair<int, int> recurse(vector<vector<int>> &adjList, string &s, int node) {
    int currSum = s[node] == 'B' ? 1 : -1;
    int count = 0;
    for (auto child: adjList[node]) {
        auto childResult = recurse(adjList, s, child);
        currSum += childResult.first;
        count += childResult.second;
    }
    if (!currSum) {
        count++;
    }
    return {currSum, count};
}

int solve() {
    int n, pi;
    string s;
    cin >> n;
    vector<vector<int>> adjList(n, vector<int>());
    for (int i = 1; i < n; ++i) {
        cin >> pi;
        adjList[pi - 1].push_back(i);
    }
    cin >> s;
    return recurse(adjList, s, 0).second;
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
