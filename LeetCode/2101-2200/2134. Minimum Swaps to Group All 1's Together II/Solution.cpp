class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                ones++;
            }
        }
        int maxRoll = -1;
        int roll = 0;
        for (int i = n - ones; i < n; ++i) {
            if (nums[i] == 1) {
                roll++;
            }
        }
        for (int i = 0; i < ones; ++i) {
            if (nums[i] == 1) {
                roll++;
            }
            if (nums[n - ones + i] == 1) {
                roll--;
            }
            if (maxRoll < roll) {
                maxRoll = roll;
            }
        }
        for (int i = ones; i < n; ++i) {
            if (nums[i] == 1) {
                roll++;
            }
            if (nums[i - ones] == 1){
                roll--;
            }
            if (maxRoll < roll) {
                maxRoll = roll;
            }
        }
        return ones - maxRoll;
    }
};