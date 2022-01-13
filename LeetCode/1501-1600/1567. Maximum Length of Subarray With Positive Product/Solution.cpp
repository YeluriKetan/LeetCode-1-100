class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, currPosLen= 0, currNegLen = 0, temp;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                currPosLen++;
                currNegLen = (currNegLen) ? currNegLen + 1 : 0;
            } else if (nums[i] == 0) {
                currPosLen= 0;
                currNegLen = 0;
            } else {
                temp = currPosLen;
                currPosLen= (currNegLen) ? currNegLen + 1 : 0;
                currNegLen = temp + 1;
            }
            maxLen = max(maxLen, currPosLen);
        }
        return maxLen;
    }
};
