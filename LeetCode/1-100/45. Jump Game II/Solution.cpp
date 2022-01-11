class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int end = nums[0], maxJump = end, steps = 0;
        for (int i = 1; i < n - 1; ++i) {
            maxJump = max(maxJump, nums[i] + i);
            if (i == end) {
                steps++;
                end = maxJump;
            }
        }
        return steps + 1;
    }
};
