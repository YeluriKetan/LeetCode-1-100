class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counter;
        for (int i = s.size() - 10; i > -1; --i) {
            counter[s.substr(i, 10)]++;
        }
        vector<string> ans;
        for (auto &currPair: counter) {
            if (currPair.second > 1) {
                ans.push_back(currPair.first);
            }
        }
        return ans;
    }
};