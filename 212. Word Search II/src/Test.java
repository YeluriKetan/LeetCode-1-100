public class Test {
    public static void main(String[] args) {
        char[][] board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
        String[] words = {"oath","pea","eat","rain"};
        Solution sol = new Solution();
        System.out.println(sol.findWords(board, words).toString());
    }
}
