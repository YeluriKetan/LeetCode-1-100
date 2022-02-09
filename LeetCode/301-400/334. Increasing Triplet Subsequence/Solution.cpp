class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int tripMid = INT_MAX;
        int newTripLow = nums[0];
        for (int curr: nums) {
            if (curr > tripMid) {
                return true;
            }
            if (newTripLow < curr) {
                tripMid = curr;
            } else if (curr < newTripLow) {
                newTripLow = curr;
            }
        }
        return false;
    }
};