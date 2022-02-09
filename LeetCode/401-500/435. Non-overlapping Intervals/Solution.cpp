bool intervalSort(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), intervalSort);
        int count = 0;
        int prevEnd = -50001;
        for (auto curr: intervals) {
            if (curr[0] < prevEnd) {
                count++;
            } else {
                prevEnd = curr[1];
            }
        }
        return count;
    }
};