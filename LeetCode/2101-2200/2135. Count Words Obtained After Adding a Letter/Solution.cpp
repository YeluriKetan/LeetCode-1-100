class Solution {
    int hashRef[26];

public:
    Solution() {
        int curr = 1;
        for (int & i : hashRef) {
            i = curr;
            curr <<= 1;
        }
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> startWordsHash;
        for (string currStartWord: startWords) {
            startWordsHash.insert(hash(currStartWord));
        }
        int currHash;
        int temp;
        int total = 0;
        for (string currTargetWord: targetWords) {
            currHash = hash(currTargetWord);
            for (char c: currTargetWord) {
                temp = currHash ^ hashRef[c - 'a'];
                if (startWordsHash.find(temp) != startWordsHash.cend()) {
                    total++;
                    break;
                }
            }
        }
        return total;
    }

    int hash(string str) {
        int val = 0;
        for (char c: str) {
            val |= hashRef[c - 'a'];
        }
        return val;
    }
};