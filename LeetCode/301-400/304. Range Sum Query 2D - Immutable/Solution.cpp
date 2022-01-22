class NumMatrix {
    vector<vector<int>> accumMat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        accumMat.insert(accumMat.begin(), m, vector<int>(n));
        int prevSum = 0;
        for (int i = 0; i < n; ++i) {
            prevSum += matrix[0][i];
            accumMat[0][i] = prevSum;
        }
        for (int i = 1; i < m; ++i) {
            prevSum = 0;
            for (int j = 0; j < n; ++j) {
                prevSum += matrix[i][j];
                accumMat[i][j] = prevSum + accumMat[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = accumMat[row2][col2];
        if (row1 > 0) {
            ans -= accumMat[row1 - 1][col2];
        }
        if (col1 > 0) {
            ans -= accumMat[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
            ans += accumMat[row1 - 1][col1 - 1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */