import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {

    private static char[][] boardS;
    private static int r,c;
    private static String wordS;
    private static boolean[][] visited;
    private static Trie trie;

    public List<String> findWords(char[][] board, String[] words) {
        boardS = board;
        r = boardS.length;
        c = boardS[0].length;
        trie = new Trie();
        ArrayList<String> list = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            wordS = words[i];
            if (exist()) {
                list.add(wordS);
            }
        }
        return list;
    }

    public boolean exist() {
        if (trie.startsWith(wordS)) {
            return true;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (boardS[i][j] == wordS.charAt(0)) {
                    visited = new boolean[r][c];
                    if (dfs(i, j, 0)) {
                        trie.insert(wordS);
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

    private class Trie {

        private HashMap<Character, Trie> map;

        public Trie() {
            map = new HashMap<>();
        }

        public void insert(String word) {
            this.insert(word, 0);
        }

        private void insert(String word, int index) {
            if (index < word.length()) {
                if (this.map.containsKey(word.charAt(index))) {
                    this.map.get(word.charAt(index)).insert(word, index + 1);
                } else {
                    Trie newTrie = new Trie();
                    newTrie.insert(word, index + 1);
                    this.map.put(word.charAt(index), newTrie);
                }
            } else {
                this.map.put('0', new Trie());
            }
        }

        public boolean search(String word) {
            return this.search(word, 0);
        }

        private boolean search(String word, int index) {
            if (index < word.length()) {
                if (this.map.containsKey(word.charAt(index))) {
                    return this.map.get(word.charAt(index)).search(word, index + 1);
                } else {
                    return false;
                }
            } else {
                return this.map.containsKey('0');
            }
        }

        public boolean startsWith(String prefix) {
            return startsWith(prefix, 0);
        }

        private boolean startsWith(String prefix, int index) {
            if (index < prefix.length()) {
                if (this.map.containsKey(prefix.charAt(index))) {
                    return this.map.get(prefix.charAt(index)).startsWith(prefix, index + 1);
                } else {
                    return false;
                }
            } else {
                return true;
            }
        }
    }
}
