class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int i = 0; i < nums.size(); ++i) {
            counter[nums[i]] += nums[i];
        }
        vector<pair<int, int>> vec;
        for (auto curr: counter) {
            vec.push_back(curr);
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });
        int prev = 0, prevMax = 0, prevPrevMax = 0, temp;
        for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
            if (it->first == prev + 1) {
                temp = max(prevMax, prevPrevMax + it->second);
            } else {
                prevMax = max(prevMax, prevPrevMax);
                temp = prevMax + it->second;
            }
            prev = it->first;
            prevPrevMax = prevMax;
            prevMax = temp;
        }
        return prevMax;
    }
};
