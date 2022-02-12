class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals(26, vector<int>(2, INT_MAX));
        int index;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            index = s[i] - 'a';
            if (intervals[index][0] == INT_MAX) {
                intervals[index][0] = i;
            }
            intervals[index][1] = i;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ans;
        int prevBegin = intervals[0][0];
        int prevEnd = intervals[0][1];
        for (int i = 1; i < 26; ++i) {
            if (intervals[i][0] == INT_MAX) {
                break;
            }
            if (intervals[i][0] < prevEnd) {
                prevEnd = max(prevEnd, intervals[i][1]);
            } else {
                ans.push_back(prevEnd - prevBegin + 1);
                prevBegin = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        ans.push_back(prevEnd - prevBegin + 1);
        return ans;
    }
};