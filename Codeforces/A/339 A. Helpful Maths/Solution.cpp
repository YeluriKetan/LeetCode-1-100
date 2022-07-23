#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    vector<int> vec;
    cin >> s;
    for (int i = 0; i < s.size(); i += 2) {
        vec.push_back(s[i] - '0');
    }
    sort(vec.begin(), vec.end());
    cout << vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        cout << "+" << vec[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
