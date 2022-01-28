class WordDictionary {

    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void addWord(String word) {
        root.add(word, 0);
    }

    public boolean search(String word) {
        return root.search(word, 0);
    }

    private static class TrieNode {
        private TrieNode[] children;
        private boolean endFlag;

        private TrieNode() {
            children = new TrieNode[26];
            endFlag = false;
        }

        private void add(String word, int index) {
            if (index >= word.length()) {
                this.endFlag = true;
            } else {
                int currInd = word.charAt(index) - 'a';
                if (children[currInd] == null) {
                    children[currInd] = new TrieNode();
                }
                children[currInd].add(word, index + 1);
            }
        }

        private boolean search(String word, int index) {
            if (index == word.length()) {
                return endFlag;
            }
            if (word.charAt(index) == '.') {
                for (int i = 0; i < 26; i++) {
                    if (children[i] != null && children[i].search(word, index + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                int currInd = word.charAt(index) - 'a';
                return children[currInd] != null && children[currInd].search(word, index + 1);
            }
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
