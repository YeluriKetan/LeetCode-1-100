class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCountTracker;
        int sum = 0;
        int count = 0;
        sumCountTracker[0] = 1;
        for (int curr: nums) {
            sum += curr;
            count += sumCountTracker[sum - k];
            sumCountTracker[sum]++;
        }
        return count;
    }
};