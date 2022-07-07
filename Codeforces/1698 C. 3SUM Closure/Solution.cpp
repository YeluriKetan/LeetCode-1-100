#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string solve() {
    int n, ai;
    bool end = false;
    cin >> n;
    vector<int> vec, count(3, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (end) {
            continue;
        }
        if (ai < 0) {
            count[0]++;
            if (count[0] > 2) {
                end = true;
            } else {
                vec.push_back(ai);
            }
        } else if (ai == 0) {
            count[1]++;
            if (count[1] <= 2) {
                vec.push_back(ai);
            }
        } else {
            count[2]++;
            if (count[2] > 2) {
                end = true;
            } else {
                vec.push_back(ai);
            }
        }
    }
    if (end) {
        return "NO";
    }
    unordered_set<int> elements(vec.begin(), vec.end());
    long long temp = 0;
    for (int i = 0; i < vec.size(); ++i) {
        temp += vec[i];
        for (int j = i + 1; j < vec.size(); ++j) {
            temp += vec[j];
            for (int k = j + 1; k < vec.size(); ++k) {
                temp += vec[k];
                if (temp < -1000000000 || temp > 1000000000) {
                    return "NO";
                }
                if (elements.find((int) temp) == elements.end()) {
                    return "NO";
                }
                temp -= vec[k];
            }
            temp -= vec[j];
        }
        temp -= vec[i];
    }
    return "YES";
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
