public class Test {
    public static void main(String[] args) {
        char[][] board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        String word = "ABCCED";
        Solution sol = new Solution();
        System.out.println((sol.exist(board, word)));
    }
}
