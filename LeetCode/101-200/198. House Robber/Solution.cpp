class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = 0, prev = 0, prevPrev = 0;
        for (int i = nums.size() - 1; i > -1; --i) {
            prevPrev = prev;
            prev = curr;
            curr = max(prev, prevPrev + nums[i]);
        }
        return curr;
    }
};