bool comp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    } else {
        return a[0] < b[0];
    }
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        int remaining = n;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][0] == -1) {
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if (intervals[j][0] == -1) {
                    continue;
                }
                if (intervals[j][0] > intervals[i][1]) {
                    break;
                }
                if (intervals[j][1] <= intervals[i][1]) {
                    intervals[j][0] = -1;
                    remaining--;
                }
            }
        }
        return remaining;
    }
};