class Solution {

    private static char[][] boardS;
    private static int r,c;
    private static String wordS;
    private static boolean[][] visited;

    public boolean exist(char[][] board, String word) {
        boardS = board;
        r = board.length;
        c = board[0].length;
        wordS = word;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == wordS.charAt(0)) {
                    visited = new boolean[r][c];
                    if (dfs(i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean dfs(int i, int j, int index) {
        if (index == wordS.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        if (isValid(i + 1, j, index + 1) && dfs(i + 1, j, index + 1)) {
            return true;
        }
        if (isValid(i - 1, j, index + 1) && dfs(i - 1, j, index + 1)) {
            return true;
        }
        if (isValid(i, j + 1, index + 1) && dfs(i, j + 1, index + 1)) {
            return true;
        }
        if (isValid(i, j - 1, index + 1) && dfs(i, j - 1, index + 1)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }

    private boolean isValid(int i, int j, int index) {
        return  (i > -1 && i < r) && (j > -1 && j < c) && (!visited[i][j]) && (boardS[i][j] == wordS.charAt(index));
    }
}
