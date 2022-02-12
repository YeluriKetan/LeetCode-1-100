class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordsSet(wordList.begin(), wordList.end());
        queue<string> frontier;
        unordered_set<string> visited;
        visited.insert(beginWord);
        frontier.push(beginWord);
        frontier.push("");
        int count = 0;
        while (!frontier.empty()) {
            string curr = frontier.front();
            frontier.pop();
            if (curr.empty()) {
                count++;
                if (!frontier.empty()) {
                    frontier.push("");
                }
                continue;
            }
            if (curr == endWord) {
                return count + 1;
            }
            for (int i = curr.size() - 1; i > -1; --i) {
                char preserve = curr[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    curr[i] = j;
                    if (wordsSet.find(curr) != wordsSet.end() && visited.find(curr) == visited.end()) {
                        frontier.push(curr);
                        visited.insert(curr);
                    }
                }
                curr[i] = preserve;
            }
        }
        return 0;
    }
};