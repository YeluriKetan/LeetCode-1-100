class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for (int i = n - 2; i > -1; --i) {
            for (int j = 0; j < n; ++j) {
                temp = INT_MAX;
                for (int k = max(0, j - 1); k <= min(n - 1, j + 1); ++k) {
                    temp = min(temp, matrix[i + 1][k]);
                }
                matrix[i][j] += temp;
            }
        }
        temp = matrix[0][0];
        for (int i = 1; i < n; ++i) {
            temp = min(temp, matrix[0][i]);
        }
        return temp;
    }
};