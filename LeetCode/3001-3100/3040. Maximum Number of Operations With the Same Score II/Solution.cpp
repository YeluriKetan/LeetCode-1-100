#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
template <>
struct std::hash<ii> {
    std::size_t operator()( const ii& k ) const {
        return (((ll) k.first) << 32) | ((ll) k.second);
    }
};

class Solution {
public:
    unordered_map<ii, int> memo;

    int helper(vector<int> &nums, int sum, int l, int r) {
        if (l >= r) return 0;
        auto it = memo.find({l, r});
        if (it != memo.end()) return it->second;
        int ans = 0;
        if (nums[l] + nums[r] == sum) ans = max(ans, helper(nums, sum, l + 1, r - 1) + 1);
        if (nums[l] + nums[l + 1] == sum) ans = max(ans, helper(nums, sum, l + 2, r) + 1);
        if (nums[r - 1] + nums[r] == sum) ans = max(ans, helper(nums, sum, l, r - 2) + 1);
        memo[{l, r}] = ans;
        return ans;
    }

    int maxOperations(vector<int>& nums) {
        int maxOper = 0;
        memo.clear();
        maxOper = max(maxOper, helper(nums, nums[0] + nums[1], 0, nums.size() - 1));
        memo.clear();
        maxOper = max(maxOper, helper(nums, nums[0] + nums[nums.size() - 1], 0, nums.size() - 1));
        memo.clear();
        maxOper = max(maxOper, helper(nums, nums[nums.size() - 1] + nums[nums.size() - 2], 0, nums.size() - 1));
        return maxOper;
    }
};