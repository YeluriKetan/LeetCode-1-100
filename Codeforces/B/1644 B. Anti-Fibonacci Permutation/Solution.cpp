#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    vector<vector<int>> vectors = {{1, 2}, {2, 1}};
    for (int i = 3; i <= n; ++i) {
        vector<int> new_vec(vectors[i - 2]);
        new_vec.insert(new_vec.end() - 1, i);
        vectors.push_back(new_vec);
        for (int j = vectors.size() - 2; j > -1; --j) {
            vectors[j].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > -1; --j) {
            cout << vectors[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        solve(n);
    }
    return 0;
}
