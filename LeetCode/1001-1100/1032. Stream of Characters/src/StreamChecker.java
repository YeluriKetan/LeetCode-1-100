class StreamChecker {

    private TrieNode begin;
    private StringBuilder sb;

    public StreamChecker(String[] words) {
        begin = new TrieNode();
        for (String curr: words) {
            add(curr);
        }
        sb = new StringBuilder();
    }

    public boolean query(char letter) {
        sb.append(letter);
        TrieNode curr = begin;
        char c;
        for (int i = sb.length() - 1; i > -1 ; i--) {
            c = sb.charAt(i);
            if (curr.children[c - 'a'] == null) {
                return false;
            }
            curr = curr.children[c - 'a'];
            if (curr.end) {
                return true;
            }

        }
        return false;
    }

    private void add(String str) {
        TrieNode curr = begin;
        char c;
        for (int i = str.length() - 1; i > -1; i--) {
            c = str.charAt(i);
            if (curr.children[c - 'a'] == null) {
                curr.children[c - 'a'] = new TrieNode();
            }
            curr = curr.children[c - 'a'];
        }
        curr.end = true;
    }

    private static class TrieNode {

        public boolean end;
        public TrieNode[] children;

        private TrieNode() {
            children = new TrieNode[26];
        }
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
