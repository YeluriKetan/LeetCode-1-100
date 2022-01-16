class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int nS = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> isPos(nS + 1, false);
        isPos[nS] = true;
        for (int i = nS - 1; i > -1; --i) {
            for (int j = min(nS, i + 20); j > i; --j) {
                if (isPos[j]) {
                    if (set.find(s.substr(i, j - i)) != set.end()) {
                        isPos[i] = true;
                        break;
                    }
                }
            }
        }
        return isPos[0];
    }
};