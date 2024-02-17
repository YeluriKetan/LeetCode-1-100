#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int s = nums[0] + nums[1];
        int oper = 1;
        for (int i = 2; i < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] == s) {
                oper++;
            } else {
                break;
            }
        }
        return oper;
    }
};