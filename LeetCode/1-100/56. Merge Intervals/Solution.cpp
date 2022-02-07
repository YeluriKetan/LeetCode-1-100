class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (vector<int> curr: intervals) {
            if (curr[0] <= end) {
                end = max(end, curr[1]);
            } else {
                ans.push_back({start, end});
                start = curr[0];
                end = curr[1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};