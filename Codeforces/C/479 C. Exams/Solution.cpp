#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &p, pair<int, int> &q) {
    if (p.first == q.first) {
        return p.second < q.second;
    } else {
        return p.first < q.first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, ai, bi;
    cin >> n;
    vector<pair<int, int>> exams(n);
    for (int i = 0; i < n; ++i) {
        cin >> ai >> bi;
        exams[i] = {bi , ai};
    }
    sort(exams.begin(), exams.end(), cmp);
    int prevMax = 0, currAns = 0;
    for (int i = 0; i < n; ++i) {
        if (exams[i].first < currAns) {
            if (exams[i].second <= prevMax) {
            } else {
                currAns = exams[i].second;
                prevMax = currAns;
            }
        } else if (exams[i].first == currAns) {
            prevMax = exams[i].second;
        } else {
            if (exams[i].second < prevMax) {
                currAns = prevMax;
            } else {
                currAns = exams[i].first;
                prevMax = exams[i].second;
            }
        }
    }
    cout << currAns << "\n";
    return 0;
}
