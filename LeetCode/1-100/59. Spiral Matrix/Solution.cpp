class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int currValue = 1;
        for (int i = 0; i < n; ++i) {
            matrix[0][i] = currValue++;
        }
        bool rightBottom = true;
        int x = 1;
        int y = n - 1;
        for (int i = n - 1; i > 0; --i) {
            if (rightBottom) {
                for (int j = x; j < x + i; ++j) {
                    matrix[j][y] = currValue++;
                }
                x = x + i - 1;
                y--;
                for (int j = y; j > y - i; --j) {
                    matrix[x][j] = currValue++;
                }
                x--;
                y = y - i + 1;
            } else {
                for (int j = x; j > x - i; --j) {
                    matrix[j][y] = currValue++;
                }
                x = x - i + 1;
                y++;
                for (int j = y; j < y + i; ++j) {
                    matrix[x][j] = currValue++;
                }
                x++;
                y = y + i - 1;
            }
            rightBottom = !rightBottom;
        }
        return matrix;
    }
};