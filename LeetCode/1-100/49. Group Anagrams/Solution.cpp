class Solution {
    int hashVector(vector<int> &vec) {
        int hash = vec.size();
        for(auto &i : vec) {
            hash ^= i + 0x9e3779b9 + ((unsigned int) hash << 6) + ((unsigned int) hash >> 2);
        }
        return hash;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> hashToVector;
        int currHashValue;
        for (auto &currString: strs) {
            vector<int> counter(26, 0);
            for (auto &currChar: currString) {
                counter[currChar - 'a']++;
            }
            currHashValue = hashVector(counter);
            if (hashToVector.find(currHashValue) == hashToVector.end()) {
                vector<string> newVec = {currString};
                hashToVector[currHashValue] = newVec;
            } else {
                hashToVector[currHashValue].push_back(currString);
            }
        }
        vector<vector<string>> ans;
        ans.reserve(hashToVector.size());
        for (auto &currPair: hashToVector) {
            ans.push_back(currPair.second);
        }
        return ans;
    }
};