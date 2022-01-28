class TrieNode {
    vector<TrieNode*> children;
    bool endWord;

public:
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        endWord = false;
    }

    void addWord(string word, int index) {
        if (index == word.size()) {
            endWord = true;
            return;
        }
        int childInd = word[index] - 'a';
        if (children[childInd] == nullptr) {
            children[childInd] = new TrieNode();
        }
        children[childInd]->addWord(word, index + 1);
    }

    bool search(string word, int index) {
        if (index == word.size()) {
            return endWord;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (children[i] != nullptr && children[i]->search(word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int childInd = word[index] - 'a';
            return children[childInd] != nullptr && children[childInd]->search(word, index + 1);
        }
    }
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        root->addWord(word, 0);
    }

    bool search(string word) {
        return root->search(word, 0);
    }
};