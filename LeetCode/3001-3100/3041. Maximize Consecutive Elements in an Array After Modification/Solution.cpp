#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
class Solution {
public:
    int maxSelectedElements(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        vector<ii> intervals;
        vector<bool> expandable;
        for (int i = 0; i < nums.size(); ++i) {
            bool expand = false;
            int start = i;
            while (++i < nums.size()) {
                if (nums[i] == nums[i - 1]) {
                    expand = true;
                } else if (nums[i] > nums[i - 1] + 1) {
                    break;
                }
            }
            intervals.emplace_back(nums[start], nums[--i]);
            expandable.push_back(expand);
        }
        for (int i = intervals.size() - 1; i > -1; --i) {
            auto curr = intervals[i];
            int currLen = curr.second - curr.first + 1;
            if (expandable[i]) currLen++;
            int left = curr.first;
            for (int j = i - 1; j > -1; --j) {
                auto prev = intervals[j];
                if (prev.second != left - 2) break;
                if (expandable[j]) {
                    currLen += prev.second - prev.first + 2;
                    left = prev.first;
                } else {
                    currLen += prev.second - prev.first + 1;
                    i = j + 1;
                    break;
                }
                if (j == 0) i = 0;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
