class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int writePointer = 0;
        int prevVal = nums[0];
        int prevCount = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == prevVal) {
                prevCount++;
            } else {
                nums[writePointer++] = prevVal;
                if (prevCount > 1) {
                    nums[writePointer++] = prevVal;
                }
                prevVal = nums[i];
                prevCount = 1;
            }
        }
        nums[writePointer++] = prevVal;
        if (prevCount > 1) {
            nums[writePointer++] = prevVal;
        }
        return writePointer;
    }
};