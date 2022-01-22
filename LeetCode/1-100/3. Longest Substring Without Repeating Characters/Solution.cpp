class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> tracker;
        int begin = 0;
        int maxLen = 0;
        unordered_map<char, int>::iterator currPointer;
        for (int i = 0; i < n; ++i) {
            currPointer = tracker.find(s[i]);
            if (currPointer != tracker.end() && currPointer->second >= begin) {
                maxLen = max(maxLen, i - begin);
                begin = currPointer->second + 1;
            }
            tracker[s[i]] = i;
        }
        maxLen = max(maxLen, n - begin);
        return maxLen;
    }
};