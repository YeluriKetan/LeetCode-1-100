class Solution {

    vector<vector<int>> memo = {{}, {1}, {1,1}};
    int done = 2;

public:
    vector<vector<int>> generate(int numRows) {
        for (int i = done + 1; i <= numRows; ++i) {
            vector<int> currVec = {1};
            for (int j = 0; j < i - 2; ++j) {
                currVec.push_back(memo[i - 1][j] + memo[i - 1][j + 1]);
            }
            currVec.push_back(1);
            memo.push_back(currVec);
            done++;
        }
        return vector<vector<int>>(memo.begin() + 1, memo.begin() + 1 + numRows);
    }
};