#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> numsSet;
        for (auto currNum: nums) {
            numsSet.insert(stoi(currNum, nullptr, 2));
        }
        string ans = string(n, '0');
        for (int i = 0; i <= n; ++i) {
            if (numsSet.find(i) == numsSet.end()) {
                for (int j = n - 1; j > -1 && i > 0; --j) {
                    if (i & 1) {
                        ans[j] = '1';
                    }
                    i >>= 1;
                }
                break;
            }
        }
        return ans;
    }
};