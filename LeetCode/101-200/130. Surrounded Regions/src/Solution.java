import java.util.Stack;

class Solution {

    private static char[][] boardS;
    private static int r;
    private static int c;

    public void solve(char[][] board) {
        boardS = board;
        r = board.length;
        c = board[0].length;
        for (int i = 0; i < c; i++) {
            if (boardS[0][i] == 'O') {
                dfs(0, i);
            }
            if (boardS[r - 1][i] == 'O') {
                dfs(r - 1, i);
            }
        }
        for (int i = 0; i < r; i++) {
            if (boardS[i][0] == 'O') {
                dfs(i, 0);
            }
            if (boardS[i][c - 1] == 'O') {
                dfs(i, c - 1);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (boardS[i][j] == '1') {
                    boardS[i][j] = 'O';
                } else if (boardS[i][j] == 'O') {
                    boardS[i][j] = 'X';
                }
            }
        }
    }

    private void dfs(int x, int y) {
        Stack<Pair> stack = new Stack<>();
        boardS[x][y] = '1';
        stack.push(new Pair(x, y));
        Pair curr;
        while (!stack.empty()) {
            curr = stack.pop();
            boardS[curr.x][curr.y] = '1';
            if (curr.x > 1 && boardS[curr.x - 1][curr.y] == 'O') {
                boardS[curr.x - 1][curr.y] = '1';
                stack.push(new Pair(curr.x - 1, curr.y));
            }
            if (curr.x < r - 1 && boardS[curr.x + 1][curr.y] == 'O') {
                boardS[curr.x + 1][curr.y] = '1';
                stack.push(new Pair(curr.x + 1, curr.y));
            }
            if (curr.y > 1 && boardS[curr.x][curr.y - 1] == 'O') {
                boardS[curr.x][curr.y - 1] = '1';
                stack.push(new Pair(curr.x, curr.y - 1));
            }
            if (curr.y < c - 1 && boardS[curr.x][curr.y + 1] == 'O') {
                boardS[curr.x][curr.y + 1] = '1';
                stack.push(new Pair(curr.x, curr.y + 1));
            }
        }
    }

    private class Pair {
        public int x;
        public int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
