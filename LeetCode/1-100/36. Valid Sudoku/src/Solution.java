import java.util.BitSet;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        BitSet[] row = new BitSet[9];
        BitSet[] col = new BitSet[9];
        BitSet[] box = new BitSet[9];
        for (int i = 0; i < 9; i++) {
            row[i] = new BitSet(9);
            col[i] = new BitSet(9);
            box[i] = new BitSet(9);
        }
        int currInt, currBox;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                currInt = board[i][j] - 49;
                currBox = ((i / 3) * 3) + (j / 3);
                if (row[i].get(currInt)) {
                    return false;
                } else {
                    row[i].set(currInt);
                }
                if (col[j].get(currInt)) {
                    return false;
                } else {
                    col[j].set(currInt);
                }
                if (box[currBox].get(currInt)) {
                    return false;
                } else {
                    box[currBox].set(currInt);
                }
            }
        }
        return true;
    }
}
