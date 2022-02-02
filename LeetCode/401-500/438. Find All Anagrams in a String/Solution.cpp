class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pSize = p.size();
        int nSize = s.size();
        vector<int> ans;
        if (pSize > nSize) {
            return ans;
        }
        vector<int> reqCounter(26);
        for (char currChar: p) {
            reqCounter[currChar - 'a']++;
        }
        vector<int> slidingCounter(26);
        for (int i = 0; i < pSize; ++i) {
            slidingCounter[s[i] - 'a']++;
        }
        if (reqCounter == slidingCounter) {
            ans.push_back(0);
        }
        for (int i = pSize; i < nSize; ++i) {
            slidingCounter[s[i] - 'a']++;
            slidingCounter[s[i - pSize] - 'a']--;
            if (reqCounter == slidingCounter) {
                ans.push_back(i - pSize + 1);
            }
        }
        return ans;
    }
};