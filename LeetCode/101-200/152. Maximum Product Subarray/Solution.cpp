class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int maxPosPro = maxProd;
        int maxNegPro = maxProd;
        int temp;
        for (int i = 1; i < n; ++i) {
            temp = maxPosPro;
            maxPosPro = max(nums[i], max(maxPosPro * nums[i], maxNegPro * nums[i]));
            maxNegPro = min(nums[i], min(temp * nums[i], maxNegPro * nums[i]));
            maxProd = max(maxProd, maxPosPro);
        }
        return maxProd;
    }
};
