class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumMap;
        for (int curr3: nums3) {
            for (int curr4: nums4) {
                sumMap[curr3 + curr4]++;
            }
        }
        int total = 0;
        for (int curr1: nums1) {
            for (int curr2: nums2) {
                total += sumMap[- curr1 - curr2];
            }
        }
        return total;
    }
};