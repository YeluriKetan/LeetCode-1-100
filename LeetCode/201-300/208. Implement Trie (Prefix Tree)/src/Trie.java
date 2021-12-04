import java.util.HashMap;

class Trie {

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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
